#include "../include/date.hpp"

Date::Date() {
    this->year = 1;
    this->month = 1;
    this->day = 1;
}

Date::Date(std::string dt) {
    size_t count = 0;
    size_t pos[2];

    for (int i = 0; i < dt.length(); i++) {
        if (dt[i] == '.') {
            pos[count++] = i; 
        }
        else if (!isdigit(dt[i])) {
            throw std::runtime_error("Unexpected token when parsing date: " + dt[i]);
        }
    }

    if (count < 2) {
        throw std::runtime_error("Unable to parse Date from `" + dt + "`");
    }

    this->year = atoi(dt.substr(0, pos[0]).c_str());
    this->month = atoi(dt.substr(pos[0], pos[1] - pos[0]).c_str());
    this->day = atoi(dt.substr(pos[1]).c_str());
}

std::string Date::toString() {
    return std::to_string(this->year) + "." + std::to_string(this->month) + "." + std::to_string(this->day);
}