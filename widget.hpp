#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class widget
{
    protected:
    int _x,_y,_sx,_sy;

    public:
        widget(int x,int y,int sx, int sy);
        virtual ~widget();

        virtual void rajzol() = 0;

        virtual void event_kezeles(genv::event) = 0;

        virtual std::string ertek_kapas()=0;

        virtual bool kivalasztva(int mx, int my);
};

#endif // WIDGET_H
