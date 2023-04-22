# PDX Parse
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

C++ library for lexical and semantical analysis on various PDX formats.

# Documentation

## ScriptLexer

* Generic Lexer intented to accept any valid PDX script file and reject invalid ones. Example input:

```
# Comment
id1 = {
    id2 = 5
    id3 = yes
    potential = {
        ROOT = {
            OR = {
                NOT = { id4 = 12.5 }
                id5 = "literal"
                id6 = 1450.1.01
            }
        }
    }
}
```

### Tokens
* String: `".*"`
* Integer: `-?\d+`
* Boolean: `(yes) | (no)`
* Float: `-?\d+\.\d+`
* Date: `\d+\.\d+\.\d+`
* Comment `#.+\n`
* Identifier: `[a-zA-Z0-9_]+`
* Operator: TBD
* Seperator: `{}=`

Note1: Operator rules depend on specific games API. ScriptLexer should accept any valid operator from any game.

Note2: Some semantical tokens (Date, Indentifier) can be written as string literals and should be lexed as such. It is up to the parser to identify them as what they are.

Note3: CK2 Wiki on string literals: `Quotes are only strictly needed when the value contains spaces, though recommended for readability.` Therefore, lexical strings and identifiers could be semantically the opposite.

# Literature 

* Introduction to Compilers and Language Design: https://www3.nd.edu/~dthain/compilerbook/
* CK2 Scripting: https://ck2.paradoxwikis.com/Scripting
* EU4 Scripting Tutorial: https://eu4.paradoxwikis.com/Scripting_Tutorial
* VIC2 Modding: https://vic2.paradoxwikis.com/Modding