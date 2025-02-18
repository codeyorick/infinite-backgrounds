//
// Created by yorick on 10 Feb 2025.
//

#ifndef ROW_H
#define ROW_H

class Row
{
public:
    virtual int next();
    virtual Row* clone() const;
    virtual ~Row() = default;
};

#endif //ROW_H
