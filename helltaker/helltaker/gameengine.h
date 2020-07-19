#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "public.h"
#include "board.h"
#include "cell.h"

class gameEngine
{
public:
    gameEngine(){};
    gameEngine(int, int);
    board& get_main_bd() { return main_bd; }
    int move_up();
    int move_down();
    int move_left();
    int move_right();
    void set_bd_1();
    void set_bd_2();
    void set_bd_3();
    bool get_whether_succeed();
    gameEngine(const gameEngine& ge);
    gameEngine& operator=(const gameEngine& ge){return copy(ge);}
    ~gameEngine();


private:
    gameEngine& copy(const gameEngine&);
    board main_bd;
    cell*tracked_cell;
    bool carry_key;
    bool whether_succeed;
};

#endif // GAME_ENGINE_H
