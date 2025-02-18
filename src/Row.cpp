//
// Created by yorick on 10 Feb 2025.
//

#include "../include/Row.h"

Row* Row::clone() const {
    return new Row(*this);
}

int Row::next()
{
    return 0;
}
