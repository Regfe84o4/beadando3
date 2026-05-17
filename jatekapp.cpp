#include "jatekapp.hpp"
#include "graphics.hpp"
#include "widget.hpp"

using namespace genv;

JatekApp::JatekApp(int width, int height)
    : _screen_width(width), _screen_height(height), _focused(-1)
{
    gout.open(width, height);
}

JatekApp::~JatekApp() {
    for (widget* w : _widgetek) delete w;
}

void JatekApp::hozzaad(widget* w) {
    _widgetek.push_back(w);
}

void JatekApp::futtat() {
    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            _focused = -1;
            for (size_t i = 0; i < _widgetek.size(); ++i) {
                if (_widgetek[i]->kivalasztva(ev.pos_x, ev.pos_y)) {
                    _focused = i;
                    break;
                }
            }
        }
        if (_focused != -1) {
            _widgetek[_focused]->event_kezeles(ev);
        }

        gout<< move_to(0, 0)
            << color(0, 0, 0)
            << box(_screen_width, _screen_height);
        for (widget* w : _widgetek) {
            w->rajzol();
        }
        gout << refresh;
    }
}
