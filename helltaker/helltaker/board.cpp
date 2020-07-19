#include "board.h"

board::board(int x, int y, int board_height, int board_width)
{
    board_h = board_height;
    board_w = board_width;

    cells = new cell[board_height * board_width];

    for(int r = 0; r < board_height; r++)
    {
        for(int c = 0; c < board_width; c++)
        {
            float _x = float(c) * float(CELL_LENGTH) + float(x);
            float _y = float(r) * float(CELL_LENGTH) + float(y);

            QPoint location(r, c);
            QPointF position(_x, _y);

            cells[r * board_width + c] = cell(location, position);
        }
    }
}

void board::set_cell_nature(cell& _cell, int _nature)
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    cells[_index].set_nature(_nature);
}

void board::set_cell_whether_trap(cell & _cell, int _whether_trap)
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    cells[_index].set_whether_trap(_whether_trap);
}

int board::get_cell_nature(cell& _cell)
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    return cells[_index].get_nature();
}

int board::get_cell_whether_trap(cell & _cell)
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    return cells[_index].get_whether_trap();
}

void board::clear_board()
{
    for(int r = 0; r < board_h; r++)
    {
        for(int c = 0; c < board_w; c++)
        {
            cells[r * board_w + c].set_nature(NO_NATURE);
            cells[r * board_w + c].set_whether_trap(NO);
        }
    }
}

cell& board::get_a_cell(int r, int c) const
{
    return cells[r * board_w + c];
}

void board::set_board_1()
{
    set_cell_nature(cells[21],WALL);
    set_cell_nature(cells[22],OPENING);
    set_cell_nature(cells[23],OPENING);
    set_cell_nature(cells[24],OPENING);
    set_cell_nature(cells[25],OPENING);
    set_cell_nature(cells[26],WALL);
    set_cell_nature(cells[27],WALL);
    set_cell_nature(cells[28],WALL);

    set_cell_nature(cells[31],WALL);
    set_cell_nature(cells[32],ENEMY);
    set_cell_nature(cells[33],WALL);
    set_cell_nature(cells[34],OPENING);
    set_cell_nature(cells[35],OPENING);
    set_cell_nature(cells[36],OPENING);
    set_cell_nature(cells[37],OPENING);
    set_cell_nature(cells[38],WALL);

    set_cell_nature(cells[41],WALL);
    set_cell_nature(cells[42],OPENING);
    set_cell_nature(cells[43],WALL);
    set_cell_nature(cells[44],WALL);
    set_cell_nature(cells[45],BOX);
    set_cell_nature(cells[46],BOX);
    set_cell_nature(cells[47],BOX);
    set_cell_nature(cells[48],WALL);

    set_cell_nature(cells[51],WALL);
    set_cell_nature(cells[52],OPENING);
    set_cell_nature(cells[53],WALL);
    set_cell_nature(cells[54],WALL);
    set_cell_nature(cells[55],OPENING);
    set_cell_nature(cells[56],OPENING);
    set_cell_nature(cells[57],OPENING);
    set_cell_nature(cells[58],WALL);

    set_cell_nature(cells[61],WALL);
    set_cell_nature(cells[62],MAN);
    set_cell_nature(cells[63],WALL);
    set_cell_nature(cells[64],WALL);
    set_cell_nature(cells[65],OPENING);
    set_cell_nature(cells[66],ENEMY);
    set_cell_nature(cells[67],OPENING);
    set_cell_nature(cells[68],WALL);

    set_cell_nature(cells[71],WALL);
    set_cell_nature(cells[72],WALL);
    set_cell_nature(cells[73],WALL);
    set_cell_nature(cells[74],WALL);
    set_cell_nature(cells[75],TARGET);
    set_cell_nature(cells[76],OPENING);
    set_cell_nature(cells[77],ENEMY);
    set_cell_nature(cells[78],WALL);

    set_cell_whether_trap(cells[34],YES);
    set_cell_whether_trap(cells[35],YES);
    set_cell_whether_trap(cells[42],YES);
    set_cell_whether_trap(cells[45],YES);
    set_cell_whether_trap(cells[46],YES);
    set_cell_whether_trap(cells[56],YES);

    for(int r=0;r<100;r++)
    {
        if(cells[r].get_nature()==NO_NATURE)
        {
            cells[r].set_nature(WALL);
        }
    }
}

void board::set_board_2()
{
   for(int r=33;r<80;r=r+10)
   {
      set_cell_nature(cells[r],ENEMY);
   }
   for(int r=35;r<80;r=r+10)
   {
       set_cell_nature(cells[r],ENEMY);
   }
   for(int r=34;r<70;r=r+10)
   {
       set_cell_nature(cells[r],OPENING);
       set_cell_whether_trap(cells[r],YES);
   }
   set_cell_nature(cells[3],WALL);
   set_cell_nature(cells[4],WALL);
   set_cell_nature(cells[5],WALL);
   set_cell_nature(cells[13],WALL);
   set_cell_nature(cells[14],WALL);
   set_cell_nature(cells[15],WALL);
   set_cell_nature(cells[23],WALL);
   set_cell_nature(cells[24],TARGET);
   set_cell_nature(cells[25],WALL);
   set_cell_nature(cells[74],MAN);
   set_cell_nature(cells[83],WALL);
   set_cell_nature(cells[84],WALL);
   set_cell_nature(cells[85],WALL);
   set_cell_nature(cells[93],WALL);
   set_cell_nature(cells[94],WALL);
   set_cell_nature(cells[95],WALL);


   for(int r=0;r<100;r++)
   {
       if(cells[r].get_nature()==NO_NATURE)
       {
           cells[r].set_nature(WALL);
       }
   }
}


void board::set_board_3()
{
    set_cell_nature(cells[14],TARGET);

    set_cell_nature(cells[20],WALL);
    set_cell_nature(cells[21],WALL);
    set_cell_nature(cells[22],WALL);
    set_cell_nature(cells[23],OPENING);
    set_cell_nature(cells[24],OPENING);
    set_cell_nature(cells[25],OPENING);
    set_cell_nature(cells[26],WALL);
    set_cell_nature(cells[27],WALL);
    set_cell_nature(cells[28],WALL);

    set_cell_nature(cells[30],WALL);
    set_cell_nature(cells[31],WALL);
    set_cell_nature(cells[32],WALL);
    set_cell_nature(cells[33],BOX);
    set_cell_nature(cells[34],TREASURE_BOX);
    set_cell_nature(cells[35],BOX);
    set_cell_nature(cells[36],WALL);
    set_cell_nature(cells[37],WALL);
    set_cell_nature(cells[38],WALL);

    set_cell_nature(cells[40],WALL);
    set_cell_nature(cells[41],WALL);
    set_cell_nature(cells[42],WALL);
    set_cell_nature(cells[43],BOX);
    set_cell_nature(cells[44],OPENING);
    set_cell_nature(cells[45],OPENING);
    set_cell_nature(cells[46],WALL);
    set_cell_nature(cells[47],OPENING);
    set_cell_nature(cells[48],WALL);

    set_cell_nature(cells[50],WALL);
    set_cell_nature(cells[51],WALL);
    set_cell_nature(cells[52],OPENING);
    set_cell_nature(cells[53],BOX);
    set_cell_nature(cells[54],BOX);
    set_cell_nature(cells[55],BOX);
    set_cell_nature(cells[56],OPENING);
    set_cell_nature(cells[57],KEY);
    set_cell_nature(cells[58],WALL);

    set_cell_nature(cells[60],WALL);
    set_cell_nature(cells[61],WALL);
    set_cell_nature(cells[62],BOX);
    set_cell_nature(cells[63],BOX);
    set_cell_nature(cells[64],OPENING);
    set_cell_nature(cells[65],OPENING);
    set_cell_nature(cells[66],BOX);
    set_cell_nature(cells[67],OPENING);
    set_cell_nature(cells[68],WALL);

    set_cell_nature(cells[70],WALL);
    set_cell_nature(cells[71],WALL);
    set_cell_nature(cells[72],MAN);
    set_cell_nature(cells[73],BOX);
    set_cell_nature(cells[74],OPENING);
    set_cell_nature(cells[75],OPENING);
    set_cell_nature(cells[76],BOX);
    set_cell_nature(cells[77],OPENING);
    set_cell_nature(cells[78],WALL);

for(int r=0;r<100;r++)
{
    if(cells[r].get_nature()==NO_NATURE)
    {
        cells[r].set_nature(WALL);
    }
}

}

int board::get_cell_nature(int a)
{
    return cells[a].get_nature();
}

int board::get_cell_whether_trap(int a)
{
    return cells[a].get_whether_trap();
}

void board::set_cell_nature(int a, int _nature)
{
    cells[a].set_nature(_nature);
}

board& board::copy(const board& bd)
{
    board_h = bd.board_h;
    board_w = bd.board_w;

    cells = new cell[board_h * board_w];

    for(int r = 0; r < board_h; r++)
    {
        for(int c = 0; c < board_w; c++)
        {
            cells[r * board_w + c] = bd.cells[r * board_w + c];
        }
    }

    return *this;
}

board::~board()
{
    delete[] cells;
    cells = NULL;
}

