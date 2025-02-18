//
// Created by yorick on 10 Feb 2025.
//

#ifndef REPEATINGROW_H
#define REPEATINGROW_H

#include <vector>

#include "Row.h"

class RepeatingRow final : public Row {
public:
    explicit RepeatingRow(std::vector<int> row);
    RepeatingRow* clone() const override;
    int next() override;
private:
    std::vector<int> _row;
    int _index = 0;
};



#endif //REPEATINGROW_H
