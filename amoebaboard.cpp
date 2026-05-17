#include "amoebaboard.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;

AmoebaBoard::AmoebaBoard(int x, int y, int sx, int sy, JatekMester* master):
    widget(x, y, sx, sy), _master(master)
{
    _rows = _master->get_rows();
    _cols = _master->get_cols();
    int cell_by_width = _sx / _cols;
    int cell_by_height = _sy / _rows;
    _cell_size = (cell_by_width < cell_by_height) ? cell_by_width : cell_by_height;
}
void AmoebaBoard::rajzol() {

    gout<< move_to(_x, _y)
        << color(220, 200, 120)
        << box(_sx, _sy)
        << color(0, 0, 0);
    for (int i = 0; i <= _rows; i++) {
        int y_line = _y + i * _cell_size;
        gout<< move_to(_x, y_line)
            << line_to(_x + _cols * _cell_size, y_line);
    }
    for (int i = 0; i <= _cols; i++) {
        int x_line = _x + i * _cell_size;
        gout << move_to(x_line, _y) << line_to(x_line, _y + _rows * _cell_size);
    }
    int piece_size = _cell_size / 2;
    if (piece_size > 30) piece_size = 30;

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            int cell = _master->get_cell(i, j);
            if (cell != 0) {
                int draw_x = _x + j * _cell_size + (_cell_size - piece_size) / 2;
                int draw_y = _y + i * _cell_size + (_cell_size - piece_size) / 2;

                if (cell == 1) gout << color(255, 0, 0);
                else gout << color(0, 0, 255);

                gout<< move_to(draw_x, draw_y)
                    << box(piece_size, piece_size);
            }
        }
    }
}
void AmoebaBoard::event_kezeles(genv::event ev) {
 if (ev.type == ev_mouse && ev.button == btn_left) {
        int cell_x = (ev.pos_x - _x) / _cell_size;
        int cell_y = (ev.pos_y - _y) / _cell_size;
        if (cell_x >= 0 && cell_x < _cols && cell_y >= 0 && cell_y < _rows) {
            bool sikerult = _master->lepes(cell_y, cell_x);
            if (sikerult && _master->is_game_over()) {
                int gyoztes = _master->get_winner();
            }
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
