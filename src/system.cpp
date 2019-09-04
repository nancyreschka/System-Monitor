#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// Return a container composed of the system's processes
vector<Process>& System::Processes() {
  vector<Process> foundProcesses{};
  // read process IDs from file system and generate Vector
  vector<int> processIds = LinuxParser::Pids();
  for (int p : processIds) {
    Process pro{p};
    foundProcesses.push_back(pro);
  }

  // sort the processes according to their CPU usage
  sort(foundProcesses.begin(), foundProcesses.end(),
       [](const Process& pa, const Process& pb) {
         return (pb.CpuUtilization() < pa.CpuUtilization());
       });
  // update list of processes
  processes_ = foundProcesses;

  return processes_;
}

// Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }