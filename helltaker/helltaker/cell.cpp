#include "cell.h"

cell::cell(QPoint& _location, QPointF& _position, int _nature,int _whether_trap)
{
    location = _location;
    position = _position;
    nature = _nature;
    whether_trap=_whether_trap;
}

cell& cell::copy(const cell& c)
{
    nature = c.nature;
    whether_trap=c.whether_trap;
    position = c.position;
    location = c.location;
    return *this;
}



cell::~cell()
{

}
