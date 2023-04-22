#ifndef PDXPARSE_SCRIPT
#define PDXPARSE_SCRIPT

#include "scanner.hpp"
#include "lexer.hpp"

/**
 * @brief Generic PDX Script token.
 * Literals are stored in respective _val variable.
 * Identifiers, Operators, Seperators stored in sval.
 * @see ScriptLexer::TOKEN
 */
class ScriptToken: public Token {
    public:
    std::string sval;
    int ival;
    double fval;
    Date dval;

    ScriptToken(Scanner scanner);
};

class ScriptLexer: public Lexer<ScriptToken> {
    public:
    /**
     * @brief Token types for generic PDX script.
     * Tokens are pretty standard with notable addition of Date literals.
     * @see Date
     */
    enum TOKEN {
        STRING,
        INTEGER,
        FLOAT,
        BOOL,
        DATE,
        IDENTIFIER,
        SEPERATOR,
        OPERATOR
    };

    ScriptLexer ();

    /**
     * @brief Rule for string literal: \"(.+)\"
     * Lexes any character except string terminator in between two quotation marks.
     * @note Not valid for languages where line break after first " is lexically incorrect.
     * @param scanner Input string.
     * @param token Token to lex into.
     * @return true Rule was applied to input.
     * @return false Input was not accepted by rule.
     */
    static bool string (Scanner scanner, ScriptToken& token);
};

#endif