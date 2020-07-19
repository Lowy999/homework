#ifndef CELL_H
#define CELL_H

#include "public.h"

class cell
{
public:
    cell() {}
    cell(QPoint &, QPointF &, int nature = NO_NATURE,int whether_trap = NO);
    cell(const cell& c) { copy(c); }
    cell& operator=(const cell& c) { return copy(c); }
    int get_nature() { return nature; }
    int get_whether_trap(){return whether_trap;}
    void set_nature(int _nature) { nature = _nature; }
    void set_whether_trap(int _whether_trap){whether_trap=_whether_trap;}
    QPointF& get_position() { return position; }
    QPoint& get_location() { return location; }
    ~cell();

private:
    QPointF position;
    QPoint location;
    cell& copy(const cell&);
    int nature;
    int whether_trap;
};

#endif // CELL_H
