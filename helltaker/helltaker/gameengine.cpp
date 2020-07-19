#include "gameengine.h"

gameEngine::gameEngine(int main_x,int main_y):main_bd(main_x,main_y,MAIN_BOARD_HEIGHT, MAIN_BOARD_WIDTH)
{
    tracked_cell=NULL;
    carry_key=false;
    whether_succeed=false;
}

gameEngine& gameEngine::copy(const gameEngine&a)
{
    main_bd=a.main_bd;
    cell* tracked_cell=new cell;
    *(tracked_cell)=*(a.tracked_cell);
    carry_key=a.carry_key;
    whether_succeed=a.whether_succeed;
    return *this;
}

int gameEngine::move_right()
{
    int num=tracked_cell->get_location().x()*MAIN_BOARD_WIDTH+tracked_cell->get_location().y();
    if(main_bd.get_cell_nature(num+1)==WALL)
    {

    }
    if(main_bd.get_cell_nature(num+1)==OPENING)
    {
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num+1,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()+1);
    }
    if(main_bd.get_cell_nature(num+1)==ENEMY)
    {
        if(main_bd.get_cell_nature(num+2)==WALL||main_bd.get_cell_nature(num+2)==BOX||main_bd.get_cell_nature(num+2)==ENEMY||main_bd.get_cell_nature(num+2)==TARGET)
        {
            main_bd.set_cell_nature(num,MAN);
            main_bd.set_cell_nature(num+1,OPENING);
        }
        else
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+1,MAN);
            main_bd.set_cell_nature(num+2,ENEMY);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()+1);

        }
    }

    if(main_bd.get_cell_nature(num+1)==BOX)
    {
        if(main_bd.get_cell_nature(num+2)==OPENING)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+1,MAN);
            main_bd.set_cell_nature(num+2,BOX);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()+1);
        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_nature(num+1)==TARGET)
    {
        whether_succeed=true;
    }
    if(main_bd.get_cell_nature(num+1)==KEY)
    {
        carry_key=true;
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num+1,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()+1);

    }

    if(main_bd.get_cell_nature(num+1)==TREASURE_BOX)
    {
        if(carry_key)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+1,MAN);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()+1);

        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_whether_trap(num+1)==1)
    {
        return -1;
    }
    else return 0;
}

int gameEngine::move_left()
{
    int num=tracked_cell->get_location().x()*MAIN_BOARD_WIDTH+tracked_cell->get_location().y();
    if(main_bd.get_cell_nature(num-1)==WALL)
    {

    }
    if(main_bd.get_cell_nature(num-1)==OPENING)
    {
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num-1,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()-1);
    }
    if(main_bd.get_cell_nature(num-1)==ENEMY)
    {
        if(main_bd.get_cell_nature(num-2)==WALL||main_bd.get_cell_nature(num-2)==BOX||main_bd.get_cell_nature(num-2)==ENEMY||main_bd.get_cell_nature(num-2)==TARGET)
        {
            main_bd.set_cell_nature(num,MAN);
            main_bd.set_cell_nature(num-1,OPENING);
        }
        else
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-1,MAN);
            main_bd.set_cell_nature(num-2,ENEMY);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()-1);

        }
    }

    if(main_bd.get_cell_nature(num-1)==BOX)
    {
        if(main_bd.get_cell_nature(num-2)==OPENING)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-1,MAN);
            main_bd.set_cell_nature(num-2,BOX);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()-1);
        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_nature(num-1)==TARGET)
    {
        whether_succeed=true;
    }
    if(main_bd.get_cell_nature(num-1)==KEY)
    {
        carry_key=true;
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num-1,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()-1);

    }

    if(main_bd.get_cell_nature(num-1)==TREASURE_BOX)
    {
        if(carry_key)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-1,MAN);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x(),tracked_cell->get_location().y()-1);

        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_whether_trap(num-1)==1)
    {
        return -1;
    }
    else return 0;
}
int gameEngine::move_down()
{
    int num=tracked_cell->get_location().x()*MAIN_BOARD_WIDTH+tracked_cell->get_location().y();
    if(main_bd.get_cell_nature(num+10)==WALL)
    {

    }
    if(main_bd.get_cell_nature(num+10)==OPENING)
    {
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num+10,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()+1,tracked_cell->get_location().y());
    }
    if(main_bd.get_cell_nature(num+10)==ENEMY)
    {
        if(main_bd.get_cell_nature(num+20)==WALL||main_bd.get_cell_nature(num+20)==BOX||main_bd.get_cell_nature(num+20)==ENEMY||main_bd.get_cell_nature(num+20)==TARGET)
        {
            main_bd.set_cell_nature(num,MAN);
            main_bd.set_cell_nature(num+10,OPENING);
        }
        else
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+10,MAN);
            main_bd.set_cell_nature(num+20,ENEMY);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()+1,tracked_cell->get_location().y());

        }
    }

    if(main_bd.get_cell_nature(num+10)==BOX)
    {
        if(main_bd.get_cell_nature(num+20)==OPENING)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+10,MAN);
            main_bd.set_cell_nature(num+20,BOX);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()+1,tracked_cell->get_location().y());
        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_nature(num+10)==TARGET)
    {
        whether_succeed=true;
    }
    if(main_bd.get_cell_nature(num+10)==KEY)
    {
        carry_key=true;
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num+10,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()+1,tracked_cell->get_location().y());

    }

    if(main_bd.get_cell_nature(num+10)==TREASURE_BOX)
    {
        if(carry_key)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num+10,MAN);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()+1,tracked_cell->get_location().y());

        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_whether_trap(num+10)==1)
    {
        return -1;
    }
    else return 0;
}

int gameEngine::move_up()
{
    int num=tracked_cell->get_location().x()*MAIN_BOARD_WIDTH+tracked_cell->get_location().y();
    if(main_bd.get_cell_nature(num-10)==WALL)
    {

    }
    if(main_bd.get_cell_nature(num-10)==OPENING)
    {
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num-10,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()-1,tracked_cell->get_location().y());
    }
    if(main_bd.get_cell_nature(num-10)==ENEMY)
    {
        if(main_bd.get_cell_nature(num-20)==WALL||main_bd.get_cell_nature(num-20)==BOX||main_bd.get_cell_nature(num-20)==ENEMY||main_bd.get_cell_nature(num-20)==TARGET)
        {
            main_bd.set_cell_nature(num,MAN);
            main_bd.set_cell_nature(num-10,OPENING);
        }
        else
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-10,MAN);
            main_bd.set_cell_nature(num-20,ENEMY);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()-1,tracked_cell->get_location().y());

        }
    }

    if(main_bd.get_cell_nature(num-10)==BOX)
    {
        if(main_bd.get_cell_nature(num-20)==OPENING)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-10,MAN);
            main_bd.set_cell_nature(num-20,BOX);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()-1,tracked_cell->get_location().y());
        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_nature(num-10)==TARGET)
    {
        whether_succeed=true;
    }
    if(main_bd.get_cell_nature(num-10)==KEY)
    {
        carry_key=true;
        main_bd.set_cell_nature(num,OPENING);
        main_bd.set_cell_nature(num-10,MAN);
        tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()-1,tracked_cell->get_location().y());

    }

    if(main_bd.get_cell_nature(num-10)==TREASURE_BOX)
    {
        if(carry_key)
        {
            main_bd.set_cell_nature(num,OPENING);
            main_bd.set_cell_nature(num-10,MAN);
            tracked_cell=&main_bd.get_a_cell(tracked_cell->get_location().x()-1,tracked_cell->get_location().y());

        }
        else
        {
            ;
        }
    }
    if(main_bd.get_cell_whether_trap(num-10)==1)
    {
        return -1;
    }
    else return 0;
}

void gameEngine::set_bd_1()
{
    main_bd.clear_board();
    main_bd.set_board_1();
    tracked_cell=&main_bd.get_a_cell(6,2);
    carry_key=false;
    whether_succeed=false;
}

void gameEngine::set_bd_2()
{
    main_bd.clear_board();
    main_bd.set_board_2();
    tracked_cell=&main_bd.get_a_cell(7,4);
    carry_key=false;
    whether_succeed=false;
}

void gameEngine::set_bd_3()
{
    main_bd.clear_board();
    main_bd.set_board_3();
    tracked_cell=&main_bd.get_a_cell(7,2);
    carry_key=false;
    whether_succeed=false;
}

bool gameEngine::get_whether_succeed()
{
    if(whether_succeed)
        return true;
    else
        return false;
}

gameEngine::~gameEngine()
{
    delete tracked_cell;
    tracked_cell=NULL;
}
