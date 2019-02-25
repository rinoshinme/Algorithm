#ifndef BUF_SIZE_H
#define BUF_SIZE_H

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <string>
#include <iostream>

#define DEF_BUF 512

long copyFile(const std::string& infilename, const std::string& outfilename, size_t insize, size_t outsize);

void testCopyFile();

#endif
