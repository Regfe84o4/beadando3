#include "amoebaboard.hpp"
#include "graphics.hpp"
using namespace genv;

AmoebaBoard::AmoebaBoard(int x, int y, int sx, int sy, int rows, int cols):
    widget(x, y, sx, sy), _rows(rows), _cols(cols)
{
    int cell_by_width = _sx / _cols;
    int cell_by_height = _sy / _rows;
    _cell_size = (cell_by_width < cell_by_height) ? cell_by_width : cell_by_height;
}
void AmoebaBoard::rajzol() {

    gout << move_to(_x, _y)
         << color(200, 180, 100)
         << box(_sx, _sy);
    for (int i = 0; i <= _rows; i++) {
        int x1 = _x;
        int y1 = _y + i * _cell_size;
        int x2 = _x + _sx;
        int y2 = y1;
        gout << move_to(x1, y1) << line_to(x2, y2);
    }
    for (int i = 0; i <= _cols; i++) {
        int x1 = _x + i * _cell_size;
        int y1 = _y;
        int x2 = x1;
        int y2 = _y + _sy;
        gout << move_to(x1, y1)
             << line_to(x2, y2);
    }
}
void AmoebaBoard::event_kezeles(genv::event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        int cell_x = (ev.pos_x - _x) / _cell_size;
        int cell_y = (ev.pos_y - _y) / _cell_size;
        if (cell_x >= 0 && cell_x < _cols && cell_y >= 0 && cell_y < _rows)
        {

        }
    }
}
std::string AmoebaBoard::ertek_kapas() {
    return "AmoebaBoard";
}

AmoebaBoard::~AmoebaBoard()
{
    //dtor
}
