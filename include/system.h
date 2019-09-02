#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
public:
  Processor &Cpu();
  std::vector<Process> &Processes();
  // Return the system's memory utilization
  float MemoryUtilization();
  long UpTime();
  int TotalProcesses();
  int RunningProcesses();
  // Return the system's kernel identifier (string)
  std::string Kernel();
  std::string OperatingSystem();

  // TODO: Define any necessary private members
private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
};

#endif