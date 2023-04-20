#ifndef PDX_PARSE_SCANNER
#define PDX_PARSE_SCANNER

#include <stddef.h>

class Scanner {
    public:
    size_t cursor;
    size_t row;
    size_t col;
    size_t len;
    char* src;

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
};

#endif