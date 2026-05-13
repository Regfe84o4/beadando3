#include "widget.hpp"


widget::widget(int x, int y, int sx, int sy):
    _x(x), _y(y), _sx(sx), _sy(sy){}

    bool widget::kivalasztva(int mx, int my)
    {
    return mx >= _x && mx <= _x + _sx &&
           my >= _y && my <= _y + _sy ;
    }


widget::~widget()
{

}
