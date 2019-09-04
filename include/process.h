#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  // constructor to initialize Process with the read process-ID from filesystem
  Process(int pid);
  // Return this process's ID
  int Pid();
  // Return the user (name) that generated this process
  std::string User();
  // Return the command that generated this process
  std::string Command();
  // Return this process's CPU utilization
  // value is given in percent
  float CpuUtilization() const;
  // Return this process's memory utilization in MB
  std::string Ram();
  // Return the age of this process (in seconds)
  long int UpTime();

  // Declare any necessary private members
 private:
  // process-ID
  int processId_;
  // user name that generated this process
  std::string user_;
  // command that generated this process
  std::string command_;
  // CPU usage of the process
  float cpuUsage_;
  // processes memory utilization
  std::string ram_;
  // age of this process
  long uptime_;
  // CPU values of a process
  enum ProcessCPUStates {
    kUtime_ = 0,
    kStime_,
    kCutime_,
    kCstime_,
    kStarttime_
  };

  // calculate the CPU utilization of this process and save in cpuUsage_
  void calculateCpuUsage();
  // determine the user name that generated this process and save in user_
  void determineUser();
  // determine the command that generated this process and save in command_
  void determineCommand();
  // determine the memory utilization of that process and save in ram_
  void determineRam();
  // determine the age of this process and save in uptime_
  void determineUptime();
};

#endif