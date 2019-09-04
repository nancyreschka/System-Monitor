#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  // Return the system's CPU
  Processor &Cpu();
  // Return a container composed of the system's processes
  // the processes are sorted by CPU usage
  std::vector<Process> &Processes();
  // Return the system's memory utilization
  float MemoryUtilization();
  // Return the number of seconds since the system started running
  long UpTime();
  // Return the total number of processes on the system
  int TotalProcesses();
  // Return the number of processes actively running on the system
  int RunningProcesses();
  // Return the system's kernel identifier (string)
  std::string Kernel();
  // Return the operating system name
  std::string OperatingSystem();

  // Define any necessary private members
 private:
  // the processor of the system
  Processor cpu_ = {};
  // container composed of the system's processes
  std::vector<Process> processes_;
};

#endif