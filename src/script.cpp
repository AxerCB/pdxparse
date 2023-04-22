#include "../include/script.hpp"

ScriptToken::ScriptToken(Scanner scanner): Token::Token (scanner) {}

ScriptLexer::ScriptLexer () {
    this->rules.push_back(&string);
}

bool ScriptLexer::check_eof(Scanner scanner, ScriptToken token) {
    if (scanner.finished()) {
        throw std::runtime_error("EOF reached when lexing token " + token.toString());
        return true;
    }
    return false;
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
    if (check_eof(scanner, token)) {
        return false;
    }
    scanner.advance();
    token.len++;
    return true;
}

bool ScriptLexer::comment (Scanner scanner, ScriptToken& token) {
    if (scanner.peek() != '#') {
        return false;
    }
    token = ScriptToken(scanner);
    token.id= TOKEN::COMMENT;
    token.sval = "";
    token.len = 1;
    while (!scanner.finished() && scanner.peek(1) != '\n' && scanner.peek(1) != '\r') {
        token.sval += scanner.advance();
        token.len++;
    }
    if (check_eof(scanner, token)) {
        return false;
    }
    scanner.advance();
    if (scanner.peek() == '\r') {
        scanner.advance();
        token.len++;
    }
    if (!scanner.finished() && scanner.peek() == '\n') {
        scanner.advance();
        token.len++;
    }
    return true;
}

bool ScriptLexer::number (Scanner scanner, ScriptToken& token) {
    // TODO: Ensure lexer if should/works for usecases like .1 -.5
    // TODO: make 1..5 invalid date as it should be. Probably parse it seperately since the automaton is pretty different. 
    if (scanner.peek() != '-' && !isdigit(scanner.peek())) {
        return false;
    }
    token = ScriptToken(scanner);
    token.id = TOKEN::INTEGER;
    token.sval = "";
    token.len = 0;

    uint8_t dots = 0;

    token.sval += scanner.peek();
    token.len++;

    while (!scanner.finished() && (isdigit(scanner.peek()) || scanner.peek() == '.')) {
        token.sval += scanner.peek();
        token.len++;
        if (scanner.peek() == '.') {
            dots++;
        }
    }

    if (!isspace(scanner.peek())) {
        return false;
    }

    switch (dots) {
    case 0:
        token.ival = atoi(token.sval.c_str());
        token.fval = token.ival;
        break;
    case 1:
        token.id = TOKEN::FLOAT;
        token.fval = atof(token.sval.c_str());
        token.ival = token.fval;
        break;
    case 2:
        token.id = TOKEN::DATE;
        token.dval = Date(token.sval);
        break;
    default:
        return false;
    }
}