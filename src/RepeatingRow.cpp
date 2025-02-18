//
// Created by yorick on 10 Feb 2025.
//

#include "../include/RepeatingRow.h"
#include <utility>

RepeatingRow::RepeatingRow(std::vector<int> row)
{
    this->_row = std::move(row);
}

RepeatingRow* RepeatingRow::clone() const {
    return new RepeatingRow(*this);
}

int RepeatingRow::next()
{
    return this->_row[this->_index++ % this->_row.size()];
}
