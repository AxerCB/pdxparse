#ifndef PDXPARSE_LEXER
#define PDXPARSE_LEXER

#include <stdexcept>
#include <vector>
#include <string>

#include "scanner.hpp"
#include "date.hpp"

class Token {
    public:
    size_t id;
    size_t pos;
    size_t row;
    size_t col;
    size_t len;

    Token (Scanner scanner);
    Token ();

    /**
     * @brief String representation of token.
     * 
     * @return std::string { row:col, id, len }
     */
    std::string toString ();
};

template <typename T>
class Lexer {
    public:
    /**
     * @brief Vector of function pointers for lexical rules of language.
     * @param Scanner Helper class for traversal input.
     * @param T& Reference to Token to be consumed.
     * @return bool Whether rule was applied to input.
     */
    std::vector<bool (*)(Scanner, T&)> rules;
    std::vector<T> tokens;
    Scanner scanner;

    bool lex ();
};

#endif