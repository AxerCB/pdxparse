#ifndef PDXPARSE_SCANNER
#define PDXPARSE_SCANNER

#include <stddef.h>
#include <string>

/**
 * @brief Helper class for Lexing a string
 * 
 */
class Scanner {
    public:
    size_t cursor = 0;
    size_t row = 0;
    size_t col = 0;
    std::string src;

    /**
     * @brief Query character cursor is at.
     * 
     * @return char Requested character.
     */
    char peek ();

    /**
     * @brief Query character with provided offset from cursor.
     * 
     * @param ahead Number of characters to skip.
     * @return char Character at cursor + ahead.
     */
    char peek (size_t ahead);

    /**
     * @brief Advance the cursor.
     * 
     * @return char The character advanced to.
     */
    char advance ();

    /**
     * @brief Advance the cursor by amount.
     * 
     * @param amount Number of characters to skip.
     * @return char Character at cursor + amount.
     */
    char advance (size_t amount);

    /**
     * @brief Seek the next occurance of a character.
     * 
     * @param c Character to search for.
     * @return size_t Offset from cursor or len if none.
     */
    size_t seek (char c); 

    /**
     * @brief Returns whether Scanner has reached EOF.
     * 
     * @return true 
     * @return false 
     */
    bool finished ();
};

#endif