#ifndef PSE_METRO_SIMULATIE_TESTFUNCS_H
#define PSE_METRO_SIMULATIE_TESTFUNCS_H

#include "iostream"
#include "string"
#include "fstream"
#include <sys/stat.h>

bool FileCompare(const std::string leftFileName, const std::string rightFileName);
bool DirectoryExists(const std::string dirname);

#endif //PSE_METRO_SIMULATIE_TESTFUNCS_H
