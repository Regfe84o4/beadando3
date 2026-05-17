#ifndef JATEKAPP_HPP
#define JATEKAPP_HPP

#include <vector>

class widget;

class JatekApp {
private:
    int _screen_width, _screen_height;
    std::vector<widget*> _widgetek;
    int _focused;

public:
    JatekApp(int width, int height);
    ~JatekApp();

    void hozzaad(widget* w);
    void futtat();
};

#endif
