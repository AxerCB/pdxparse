#ifndef PDXPARSE_IO
#define PDXPARSE_IO

#include <stdexcept>
#include <iostream>
#include <string>

/**
 * @brief Load file into string.
 * 
 * @param path Relative or absolute path to file
 * @return std::string File contents or std::string(nullptr).
 * @throws std::runtime_error Failed fopen()
 */
std::string read (std::string path);

#endif