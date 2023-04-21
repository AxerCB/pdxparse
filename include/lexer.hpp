#ifndef PDXPARSE_LEXER
#define PDXPARSE_LEXER

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

#include "scanner.hpp"

struct Token {
    size_t id;
    size_t pos;
    size_t row;
    size_t col;
};

class Lexer {
    public:
    std::vector<bool (*)(Scanner)> rules;
    std::vector<Token> tokens;
    Scanner scanner;

    void read (std::string path);

    bool lex () {
        for (int i = 0; i < rules.size(); i++) {
            if (rules[i](scanner)) {
                return true;
            }
        }
        throw std::runtime_error("Unexpected token " + std::string(1, scanner.peek()) + " at" + std::to_string(scanner.row) + ":" + std::to_string(scanner.col));
        return false;
    }
};

#endif