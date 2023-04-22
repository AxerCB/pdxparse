#include "../include/io.hpp"

std::string read (std::string path) {
    FILE* file = fopen(path.c_str(), "r");

    if (!file) {
        throw std::runtime_error("Unable to load file " + path);
        return std::string(nullptr);
    }

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char buf[len+1];

    fread(buf, 1, len, file);
    buf[len] = '\0';

    fclose(file);

    return std::string(buf);
}