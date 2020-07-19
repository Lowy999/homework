#ifndef BOARD_H
#define BOARD_H

#include "public.h"
#include "cell.h"

class board
{
public:
    board(){};
    board(int, int, int, int);
    board(const board& bd) { copy(bd); }
    cell& get_a_cell(int, int) const;
    void clear_board();
    void set_cell_nature(cell &, int);
    void set_cell_whether_trap(cell&,int);
    int get_cell_nature(cell &);
    int get_cell_whether_trap(cell &);
    void set_board_1();
    void set_board_2();
    void set_board_3();
    int get_cell_nature(int);
    int get_cell_whether_trap(int);
    void set_cell_nature(int, int);
    board& operator=(const board& bd) { return copy(bd); }
    ~board();

private:
    board& copy(const board&);
    cell* cells;
    int board_h;
    int board_w;
};

#endif // BOARD_H
