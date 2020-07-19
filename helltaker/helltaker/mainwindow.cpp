#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIcon"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    where=0;
    ui->setupUi(this);
    ge = new gameEngine(ui->frm_main->x(),ui->frm_main->y());
    setFocusPolicy(Qt::StrongFocus);
    step=0;
    blood=0;
    fail=false;
    succeed=false;
    finally_succeed=false;
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(push_btn_1()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(push_btn_2()));
    setStyleSheet("QPushButton{background: transparent;}");
    ui->btn_1->setFocusPolicy(Qt::NoFocus);
    ui->btn_2->setFocusPolicy(Qt::NoFocus);
    QIcon icon(":new/prefix1/resource/kei.jpeg");
    setWindowIcon(icon);
    setWindowTitle("Helltaker");
}


void MainWindow::succeed_fail()
{
     if(step==0||blood==0)
    {
        fail=true;
        succeed=false;
    }

    if(ge->get_whether_succeed())
    {
        fail=false;
        succeed=true;
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();

    switch(key)
    {
    case Qt::Key_Left:
        blood=ge->move_left()+blood;
        break;

    case Qt::Key_Right:
        blood=ge->move_right()+blood;
        break;

    case Qt::Key_Up:
        blood=ge->move_up()+blood;
        break;

    case Qt::Key_Down:
        blood=ge->move_down()+blood;
        break;

    default:
        break;
    }
    step--;
    succeed_fail();
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(finally_succeed==true)
    {
        QPixmap pix;
        if(where==2)
        {
            pix.load(":new/prefix1/resource/bd_1_success.png");
        }
        if(where==3)
        {
            pix.load(":new/prefix1/resource/bd_2_success.png");
        }
        if(where==4)
        {
            pix.load(":new/prefix1/resource/bd_3_success.png");
        }
            painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);

    }
    else if(fail==true)
    {
        QPixmap pix;
        pix.load(":new/prefix1/resource/badend.png");
        painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);//绘制失败的图
    }
    else if(succeed==true)
    {
        switch (where) {
        case 1:
        {
            QPixmap pix;
            pix.load(":new/prefix1/resource/bd_1_conversation.png");
            painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);


        }
            break;
        case 2:
        {
            QPixmap pix;
            pix.load(":new/prefix1/resource/bd_2_conversation.png");
            painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);

        }
            break;
        case 3:
        {
            QPixmap pix;
            pix.load(":new/prefix1/resource/bd_3_conversation.png");
            painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);
        }
            break;


        }
    }
    else
    {
        switch(where)
        {
        case 0:
        {
            QPixmap pix;
            pix.load(":new/prefix1/resource/begin.png");
            painter.drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,pix);
        }
            break;
        case 1:
        case 2:
        case 3:
        {
            for(int r=0;r<MAIN_BOARD_HEIGHT;r++)
            {
                for(int c=0;c<MAIN_BOARD_WIDTH;c++)
                {
                    QPixmap pix;
                    cell acell=ge->get_main_bd().get_a_cell(r,c);
                    if(acell.get_nature()==WALL)pix.load(":new/prefix1/resource/WALL.png");
                    if(acell.get_nature()==BOX&&acell.get_whether_trap()==0)pix.load(":new/prefix1/resource/BOX.png");
                    if(acell.get_nature()==BOX&&acell.get_whether_trap()==1)pix.load(":new/prefix1/resource/TRAP+BOX.png");
                    if(acell.get_nature()==TARGET)
                    {
                        if(where==1)pix.load(":new/prefix1/resource/TARGET.png");
                        if(where==2)pix.load(":new/prefix1/resource/TARGET_2.png");
                        if(where==3)pix.load(":new/prefix1/resource/TARGET_3.png");
                    }
                    if(acell.get_nature()==MAN)pix.load(":new/prefix1/resource/MAN.png");
                    if(acell.get_nature()==ENEMY)pix.load(":new/prefix1/resource/ENEMY.png");
                    if(acell.get_nature()==OPENING&&acell.get_whether_trap()==0)pix.load(":new/prefix1/resource/OPENING.png");
                    if(acell.get_nature()==OPENING&&acell.get_whether_trap()==1)pix.load(":new/prefix1/resource/TRAP.png");
                    if(acell.get_nature()==KEY)pix.load(":new/prefix1/resource/KEY.png");
                    if(acell.get_nature()==TREASURE_BOX)pix.load(":new/prefix1/resource/TREASURE_BOX.png");
                    painter.drawPixmap(c*CELL_LENGTH,r*CELL_LENGTH,CELL_LENGTH,CELL_LENGTH,pix);
                }
            }
          QPixmap wall;
          wall.load(":new/prefix1/resource/WALL.png");
          painter.drawPixmap(0,600,600,160,wall);
          QPixmap number;
          QPixmap gate;
          switch (blood)
          {
          case 1:
          {
             gate.load(":new/prefix1/resource/111.png");
             painter.drawPixmap(480,500,120,270,gate);
          }
              break;
          case 2:
          {
             gate.load(":new/prefix1/resource/222.png");
             painter.drawPixmap(481,500,120,270,gate);
          }
              break;
          case 3:
          {
             gate.load(":new/prefix1/resource/333.png");
             painter.drawPixmap(480,500,120,270,gate);
          }
              break;
          case 4:
          {
              gate.load(":new/prefix1/resource/444.png");
              painter.drawPixmap(480,500,120,270,gate);
          }
              break;
          default:
              break;
          }



          switch(step)
          {
          case 1:
          {
              number.load(":new/prefix1/resource/1.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 2:
          {
              number.load(":new/prefix1/resource/2.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 3:
          {
              number.load(":new/prefix1/resource/3.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 4:
          {
              number.load(":new/prefix1/resource/4.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 5:
          {
              number.load(":new/prefix1/resource/5.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 6:
          {
              number.load(":new/prefix1/resource/6.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 7:
          {
              number.load(":new/prefix1/resource/7.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 8:
          {
              number.load(":new/prefix1/resource/8.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 9:
          {
              number.load(":new/prefix1/resource/9.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 10:
          {
              number.load(":new/prefix1/resource/10.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 11:
          {
              number.load(":new/prefix1/resource/11.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 12:
          {
              number.load(":new/prefix1/resource/12.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 13:
          {
              number.load(":new/prefix1/resource/13.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 14:
          {
              number.load(":new/prefix1/resource/14.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 15:
          {
              number.load(":new/prefix1/resource/15.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 16:
          {
              number.load(":new/prefix1/resource/16.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 17:
          {
              number.load(":new/prefix1/resource/17.png");
            painter.drawPixmap(0,500,120,270,number);
          }
              break;
          case 18:
          {
              number.load(":new/prefix1/resource/18.png");
              painter.drawPixmap(0,500,120,270,number);
          }
              break;


        case 19:
        {
              number.load(":new/prefix1/resource/19.png");
              painter.drawPixmap(0,500,120,270,number);
        }
            break;
         case 20:
          {
              number.load(":new/prefix1/resource/20.png");
             painter.drawPixmap(0,500,120,270,number);
          }
              break;


        default:
              break;
}


        }

        }
    }
}

void MainWindow::push_btn_1()
{
   where++;
   if(where==1)
   {
       fail=false;
       succeed=false;
       blood=BLOOD;
       step=FIRST_STEP;
       ge->set_bd_1();
       ///////////////
   //    ui->btn_1->setVisible(false);
   }
   if(where==2)
   {
       fail=false;
       succeed=false;
       finally_succeed=true;
       repaint();
       Sleep(3000);
       finally_succeed=false;
       blood=BLOOD;
       step=SECOND_STEP;
       ge->set_bd_2();
       //////////////////
  //      ui->btn_1->setVisible(false);
   }
   if(where==3)
   {
       fail=false;
       succeed=false;
       finally_succeed=true;
       repaint();
       Sleep(3000);
       finally_succeed=false;
       blood=BLOOD;
       step=THIRD_STEP;
       ge->set_bd_3();
       //////////////
    //    ui->btn_1->setVisible(false);
   }
   if(where==4)
   {
       fail=false;
       succeed=false;
       finally_succeed=true;
   }

   update();
}

void MainWindow::push_btn_2()
{
    fail=true;
    succeed=false;
    update();
}


MainWindow::~MainWindow()
{
    delete ui;
}

