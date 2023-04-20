#include "../include/scanner.hpp"

char Scanner::peek () {
    return src[cursor];        
}

char Scanner::peek (size_t ahead) {
    return src[cursor + ahead];
}

char Scanner::advance () {
    if (peek() == '\n') {
        row++;
        col = 0;
    }
    else col++;
    return src[++cursor];
}

char Scanner::advance (size_t amount) {
    for (size_t i = 0; i < amount; i++) {
        advance();
    }
    return src[cursor];
}

size_t Scanner::seek (char c) {
    size_t pos = cursor;
    while (pos < len) {
        if (src[pos] == c) {
            return pos - cursor;
        }
        pos++;
    }
    return len;
}