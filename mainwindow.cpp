#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QElapsedTimer>
#include<QThread>
#include<QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ 
   ui->setupUi(this);
   auto board1=new board(this);
   auto motion1=new motion(this,board1);
   this->myboard=board1;
   this->mymotion=motion1;
   auto StatusUpdate=new statusObserve(nullptr,board1);
   auto CircleTest=new circleTest(nullptr,motion1);
   this->mytest=CircleTest;
   this->myobserver=StatusUpdate;
   QThread *sub_thread1= new QThread;
   QThread *sub_thread2= new QThread;
   this->mythread1=sub_thread1;
   this->mythread2=sub_thread2;
   StatusUpdate->moveToThread(sub_thread1);
   CircleTest->moveToThread(sub_thread2);
   sub_thread1->start();
   sub_thread2->start();
   connect(ui->btn_init,&QPushButton::clicked,this,&MainWindow::Board_init);
   connect(ui->btn_init,&QPushButton::clicked,StatusUpdate,&statusObserve::status_update);
   connect(ui->btn_close,&QPushButton::clicked,this,&MainWindow::Board_close);
   connect(ui->btn_axis_enable,&QPushButton::clicked,this,&MainWindow::Axis_enable);
   connect(ui->btn_axis_disable,&QPushButton::clicked,this,&MainWindow::Axis_disable);
   connect(ui->btn_sp_z,&QPushButton::clicked,[=](){
       this->Speed_move(1);
   });
   connect(ui->btn_sp_f,&QPushButton::clicked,[=](){
       this->Speed_move(0);
   });
   connect(ui->btn_sp_t,&QPushButton::clicked,this,&MainWindow::Move_stop);
   connect(ui->btn_sp_home,&QPushButton::clicked,this,&MainWindow::Home_move);
   connect(ui->btn_pos_z,&QPushButton::clicked,[=](){
       this->Position_move(1);
   });
   connect(ui->btn_pos_f,&QPushButton::clicked,[=](){
      this->Position_move(-1);
   });
   connect(ui->btn_pos_t,&QPushButton::clicked,this,&MainWindow::Move_stop);
   connect(ui->btn_pos_home,&QPushButton::clicked,this,&MainWindow::Home_move);
   connect(ui->btn_ct_t,&QPushButton::clicked,this,&MainWindow::Move_stop);
   connect(ui->btn_ct_home,&QPushButton::clicked,this,&MainWindow::Home_move);
   connect(ui->btn_ct_f,&QPushButton::clicked,[=](){
       this->circle_test(-1);
   });
   connect(ui->btn_ct_z,&QPushButton::clicked,[=](){
       this->circle_test(1);
   });
   connect(ui->btn_ct_home,&QPushButton::clicked,this,&MainWindow::Home_move);
   connect(ui->btn_ct_t,&QPushButton::clicked,this,&MainWindow::circle_stop);
   connect(StatusUpdate,&statusObserve::status,this,&MainWindow::update_status);
   connect(CircleTest,&circleTest::update_process,this,&MainWindow::circle_process);
   connect(CircleTest,&circleTest::test_complete,this,&MainWindow::circle_comlete);
   connect(CircleTest,&circleTest::test_stop,this,&MainWindow::test_stop);
   connect(this,&MainWindow::circle_start,CircleTest,&circleTest::circle_test);
}
void MainWindow::Board_init()
{
    int ret=myboard->_board_init();
    if(ret==1)
    {
        QMessageBox::information(this,"提示","Connection Failed ,Try Again ! ");
        return;
    }
    else if(ret==0)
    {
        QMessageBox::information(this,"提示","Initialization Completed ! ");
        return;
    }
    else
    {
      QMessageBox::information(this,"提示","Innitialization Failed,Try Again! ");
    }
}
void MainWindow::Axis_enable()
{
    int ret =myboard->_axis_enable();
    if(ret==-1)
    {
        QMessageBox::information(this,"提示","Error Bus ,Try Again ! ");
        return;
    }
    else
    {
        QMessageBox::information(this,"提示","Enable Success ! ");
        return;
    }
//    else
//    {
//        QMessageBox::information(this,"提示","Enable Failed ! ");
//        return;
//    }
}
void MainWindow::Axis_disable()
{
    if(myboard->_axis_disable())
    {
        QMessageBox::information(this,"提示","Disable Success ! ");
    }
    else
    {
        QMessageBox::information(this,"提示","Disable Failed ! ");
    }
}
void MainWindow::Board_close()
{
    if(!myboard->_board_close())
    {
       QMessageBox::information(this,"提示","Board Close Failed ! ");
    }
}
void MainWindow::Speed_move( int direction)
{
    if(mymotion->stop_move()==1)
    {
       QMessageBox::information(this,"提示","Machine Disable ! ");
       return;
    }
    if(direction==1)
    {
        ui->btn_sp_z->setDisabled(true);
        ui->btn_sp_f->setEnabled(true);
    }
    else
    {
        ui->btn_sp_f->setDisabled(true);
        ui->btn_sp_z->setEnabled(true);
    }
    mymotion->set_direction_v(direction);
    mymotion->set_speed(ui->text_speed->text().toDouble());
    QElapsedTimer t;
    while(t.elapsed()<200);//延时0.2s
    if(mymotion->speed_move()==1)
    {
        QMessageBox::information(this,"提示","Machine Disable ! ");
        ui->btn_sp_f->setEnabled(true);
        ui->btn_sp_z->setEnabled(true);
        ui->btn_pos_f->setEnabled(true);
        ui->btn_pos_z->setEnabled(true);
    }
}
void MainWindow::Move_stop()
{
     if(mymotion->stop_move()==1)
         return;
     ui->btn_sp_f->setEnabled(true);
     ui->btn_sp_z->setEnabled(true);
     ui->btn_pos_f->setEnabled(true);
     ui->btn_pos_z->setEnabled(true);
     ui->btn_sp_home->setEnabled(true);
     ui->btn_pos_home->setEnabled(true);
}
void MainWindow::Position_move(int direction)
{
    ui->btn_pos_z->setDisabled(true);
    ui->btn_pos_f->setDisabled(true);
    ui->btn_pos_home->setDisabled(true);
    mymotion->set_direction_p(direction);
    mymotion->set_position(ui->text_pos->text().toDouble());
    mymotion->set_speed(5);
    if(mymotion->position_move()==1)
    {
       QMessageBox::information(this,"提示","Machine Disable ! ");
    }
    ui->btn_pos_z->setEnabled(true);
    ui->btn_pos_f->setEnabled(true);
    ui->btn_pos_home->setEnabled(true);
}
void MainWindow::Home_move()
{
    if(mymotion->home_move()==1)
    {
       QMessageBox::information(this,"提示","Machine Disable ! ");
       return;
    }
}
void  MainWindow::update_status(double pos,int status_word)
{
    ui->coder_pos->setText(QString::number(pos/this->mymotion->get_count_convert(),'f',3));
    ui->coder_pos->update();
    switch (status_word)
    {
    case 0:
        ui->axis_status->setText("未启动 ");
        ui->axis_status->update();
        break;
    case 1:
        ui->axis_status->setText("禁止启动 ");
        ui->axis_status->update();
        break;

    case 2:
        ui->axis_status->setText("准备启动 ");
        ui->axis_status->update();
        break;
    case 3:
        ui->axis_status->setText("启动 ");
        ui->axis_status->update();
        break;
    case 4:
        ui->axis_status->setText("操作使能 ");
        ui->axis_status->update();
        break;
    case 5:
        ui->axis_status->setText("停止 ");
        ui->axis_status->update();
        break;
    case 6:
        ui->axis_status->setText("错误触发 ");
        ui->axis_status->update();
        break;
    case 7:
        ui->axis_status->setText("错误 ");
        ui->axis_status->update();
        break;
    default:
        break;
    }
}
void  MainWindow::circle_test(int direction)
{
    if(myboard->_get_status()!=4)
    {
        QMessageBox::information(this,"提示","Machine Disable ! ");
        return;
    }
    ui->btn_ct_z->setDisabled(true);
    ui->btn_ct_f->setDisabled(true);
    ui->btn_ct_home->setDisabled(true);
    ui->label_times->setText(ui->text_times_c->text());
    ui->label_times->update();
    ui->label_points->setText(ui->text_point_c->text());
    ui->label_points->update();
    //修改停止标记
    this->mytest->stop_flag=false;
    int circle_times(ui->text_times_c->text().toInt());
    int circle_points(ui->text_point_c->text().toInt());
    double length(ui->text_pos_c->text().toDouble());
    double speed(ui->text_speed_c->text().toDouble());
    emit circle_start(circle_times, circle_points, length,speed,direction);
}
void  MainWindow::circle_stop()
{

    this->mytest->stop_flag=true;

}
void MainWindow::observe_stop()
{

    this->myobserver->stop_flag=true;

}
void MainWindow::test_stop()
{
    ui->btn_ct_z->setEnabled(true);
    ui->btn_ct_f->setEnabled(true);
    ui->btn_ct_home->setEnabled(true);
    QMessageBox::information(this,"提示","Test Interrupt ! ");
    ui->label_times->setText("0");
    ui->label_times->update();
    ui->label_points->setText("0");
    ui->label_points->update();
}

void MainWindow::circle_comlete()
{
    ui->btn_ct_z->setEnabled(true);
    ui->btn_ct_f->setEnabled(true);
    ui->btn_ct_home->setEnabled(true);
    QMessageBox::information(this,"提示","Test Complete ! ");
    ui->label_times->setText("0");
    ui->label_times->update();
    ui->label_points->setText("0");
    ui->label_points->update();
}
void MainWindow::circle_process(int circles,int points)
{
    ui->label_points->setText( QString::number(points,10));//更新测试进度
    ui->label_times->update();
    int timeshow=((circles&1)==0)?circles/2:circles/2+1;
    ui->label_times->setText( QString::number(timeshow,10));//更新测试进度
    ui->label_times->update();
}
void MainWindow::quit_thread(QThread* thread)
{
    if(thread->isRunning())
    {
       thread->quit();
       thread->wait();
       delete thread;
    }
}
MainWindow::~MainWindow()
{
    circle_stop();
    observe_stop();
    quit_thread(mythread1);
    quit_thread(mythread2);
    this->Board_close();
    delete myboard;
    delete mymotion;
    delete mytest;
    delete myobserver;
    delete ui;    
}

