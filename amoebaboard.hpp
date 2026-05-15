#ifndef AMOEBABOARD_HPP
#define AMOEBABOARD_HPP

#include "widget.hpp"
#include <vector>

class AmoebaBoard : public widget {
protected:
    int _rows, _cols;
    int _cell_size;
public:
    AmoebaBoard(int x, int y, int size_x, int size_y, int rows, int cols);
    virtual ~AmoebaBoard();

    void rajzol() override;
    void event_kezeles(genv::event ev) override;
    std::string ertek_kapas() override;
};


#endif // AMOEBABOARD_HPP
