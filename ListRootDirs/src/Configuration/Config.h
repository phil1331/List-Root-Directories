#pragma once

inline std::sregex_iterator invalid_iter;

#if __has_include (<Windows.h>) 
#define PCLOSE_S _pclose
#define POPEN_S _popen
#else
#define PCLOSE_S pclose
#define POPEN_S popen
#endif