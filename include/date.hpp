#ifndef PDXPARSE_DATE
#define PDXPARSE_DATE

#include <stdexcept>
#include <string>

#include <stddef.h>
#include <stdint.h>

class Date {
    public:
    uint8_t day;
    uint8_t month;
    uint16_t year;

    /**
     * @brief Constructs date at 1.1.1
     * 
     */
    Date();
    /**
     * @brief Construct a new Date from string.
     * Starting from 1.1.1
     * Note: Negative dates not supported.
     * @param dt YYYY.MM.dd
     */
    Date(std::string dt);

    std::string toString();
};

#endif