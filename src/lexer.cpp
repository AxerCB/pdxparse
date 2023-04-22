#include "../include/lexer.hpp"

Token::Token () {}

Token::Token (Scanner scanner) {
    this->pos = scanner.cursor;
    this->col = scanner.col;
    this->row = scanner.row;
    this->len = 0;
}

std::string Token::toString () {
    return "{ " +  std::to_string(row) + ":" + std::to_string(col) + ", " + std::to_string(id) + ", " + std::to_string(len) + " }";
}

template <class T>
bool Lexer<T>::lex () {
    T& token;
    for (int i = 0; i < rules.size(); i++) {
        if (rules[i](scanner, token)) {
            tokens.push_back(token);
            return true;
        }
    }
    throw std::runtime_error("Unexpected token " + std::string(1, scanner.peek()) + " at" + std::to_string(scanner.row) + ":" + std::to_string(scanner.col));
    return false;
}

