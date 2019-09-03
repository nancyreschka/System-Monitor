#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Processor {
 public:
  float Utilization();

  // constructor
  Processor();

  // Declare any necessary private members
 private:
  // the values of the CPU that were previously determined
  // previous total cpu time since boot =
  // user+nice+system+idle+iowait+irq+softirq+steal
  float prevTotalCpuTime;
  // previous idle time since boot = idle + iowait
  float prevIdleCpuTime;

  // convert the given string vector into a long vector
  vector<long> convertToLong(vector<string> values);
};

#endif