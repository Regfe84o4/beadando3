#include "graphics.hpp"
#include "szambeallitoB.hpp"
#include "kivalasztoA.hpp"
#include <vector>
#include <fstream>

using namespace genv;
using namespace std;

void event_loop(vector<widget*>& widgetek) {
    event ev;
    widget* focused_widget = nullptr;

    while (gin >> ev && ev.keycode != key_escape) {

        if (ev.type == ev_mouse && ev.button == btn_left) {

            for (widget* w : widgetek) {

                if (w->kivalasztva(ev.pos_x, ev.pos_y)) {

                    if (focused_widget) focused_widget->set_focus(false);

                    focused_widget = w;
                    focused_widget->set_focus(true);
                    w->event_kezeles(ev);
                    break;
                }
            }
            if (focused_widget && !focused_widget->kivalasztva(ev.pos_x, ev.pos_y)) {
                focused_widget->set_focus(false);
                focused_widget = nullptr;
            }
        }
        else if (ev.type == ev_key) {
            if (focused_widget) {
                focused_widget->event_kezeles(ev);
            }
        }

        else {
            if (focused_widget) {
                focused_widget->event_kezeles(ev);
            }
        }

        gout<< move_to(0,0)
            << color(0,0,0)
            << box(600, 400);
        for (widget* w : widgetek) w->rajzol();
        gout << refresh;
    }
}

int main()
{

    gout.open(600, 400);
    vector<widget*> widgetek;

    widgetek.push_back(new szambeallitoB(40, 50, 300, 40, 0, 100));

    widgetek.push_back(new szambeallitoB(40, 100, 300, 40, 43, 155));

    vector<string> szamok = {"1", "2", "3", "4", "5", "6", "7"};
    widgetek.push_back(new kivalasztoA(350, 50, 200, 90, szamok));

    vector<string> szamokbetuvel = {"egy", "kettõ", "három"};
    widgetek.push_back(new kivalasztoA(350, 200, 200, 100, szamokbetuvel));

    event_loop(widgetek);

    ofstream f("kimenet.txt");
    for (widget* w : widgetek)
    {
        f << w->ertek_kapas() << endl;
    }
    f.close();
    for (widget* w : widgetek) delete w;


    return 0;
}
