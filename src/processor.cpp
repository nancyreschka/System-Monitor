#include "processor.h"
#include <string>
#include <vector>
#include "linux_parser.h"

using std::string;
using std::vector;

Processor::Processor() : prevTotalCpuTime(0.0), prevIdleCpuTime(0.0){};

// Return the aggregate CPU utilization
float Processor::Utilization() {
  // read current cpu values from file system
  vector<long> cpuValues = convertToLong(LinuxParser::CpuUtilization());
  // total cpu time since boot = user+nice+system+idle+iowait+irq+softirq+steal
  float totalCpuTime = cpuValues[0] + cpuValues[1] + cpuValues[2] +
                       cpuValues[3] + cpuValues[4] + cpuValues[5] +
                       cpuValues[6] + cpuValues[7];
  // idle time since boot = idle + iowait
  float idleCpuTime = cpuValues[3] + cpuValues[4];

  // calculate the cpu usage since last update
  float diffIdle = idleCpuTime - prevIdleCpuTime;
  float diffTotal = totalCpuTime - prevTotalCpuTime;
  float diffUsage = (diffTotal - diffIdle) / diffTotal;
  // remember the total and idle times for next check
  prevIdleCpuTime = idleCpuTime;
  prevTotalCpuTime = totalCpuTime;
  return diffUsage;
}

// convert the given string vector into a long vector
vector<long> Processor::convertToLong(vector<string> values) {
  vector<long> convertedValues{};

  for (int it = 0; it < (int)values.size(); it++) {
    convertedValues.push_back(std::stol(values[it]));
  }
  return convertedValues;
}