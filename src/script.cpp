#include "../include/script.hpp"

ScriptToken::ScriptToken(Scanner scanner): Token::Token (scanner) {}

ScriptLexer::ScriptLexer () {
    this->rules.push_back(&string);
}

bool ScriptLexer::string (Scanner scanner, ScriptToken& token) {
    if (scanner.peek() != '\"') {
        return false;
    }
    token = ScriptToken(scanner);
    token.id = TOKEN::STRING;
    token.sval = "";
    token.len = 1;
    while (!scanner.finished() && scanner.advance() != '\"') {
        token.sval += scanner.peek();
        token.len++;
    }
    if (scanner.finished()) {
        throw std::runtime_error("Reached EOF when lexing string literal: " + token.toString());
    }
    else if (scanner.peek() == '\"') {
        scanner.advance();
        token.len++;
        return true;
    }
    return false;
}