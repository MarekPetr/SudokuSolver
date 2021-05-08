//
// Created by petr on 08.05.21.
//

#ifndef SUDOKU_UTILS_H
#define SUDOKU_UTILS_H


#include <sstream>

class Formatter
{
public:
    template<class Val> Formatter& operator<<(const Val& val)
    {
        ss_ << val;
        return * this;
    }
    operator std::string() const { return ss_.str().c_str(); }
private:
    std::stringstream ss_;
};


#endif //SUDOKU_UTILS_H
