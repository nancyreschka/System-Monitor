#ifndef FORMAT_H
#define FORMAT_H

#include <string>

namespace Format {
// determine string HH:MM:SS from given seconds
std::string ElapsedTime(long times);
// check if calculated number is smaller than 10 and return the appropriate
// string return 0x for number smaller than 10 otherwise return the number
std::string TimeValueToString(long time);
};  // namespace Format

#endif