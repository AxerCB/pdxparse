#include "../include/lexer.hpp"

void Lexer::read (std::string path) {
    FILE* file = fopen(path.c_str(), "r");

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char buf[len+1];

    fread(buf, 1, len, file);
    buf[len] = '\0';

    fclose(file);

    this->scanner = Scanner();
    this->scanner.src = std::string(buf);
}

bool Lexer::lex () {
    for (int i = 0; i < rules.size(); i++) {
        if (rules[i](scanner)) {
            return true;
        }
    }
    throw std::runtime_error("Unexpected token " + std::string(1, scanner.peek()) + " at" + std::to_string(scanner.row) + ":" + std::to_string(scanner.col));
    return false;
}