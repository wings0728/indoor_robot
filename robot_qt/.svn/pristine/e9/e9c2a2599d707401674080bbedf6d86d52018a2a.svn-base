/**
  ******************************************************************************
  * 公司    T3
  * 文件名  main.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "controller/T3MainController.hpp"
#include "ros/qnode.hpp"
/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    /***********ros*************/
    interface::QNode *qnode = interface::QNode::getInstance();
    //T3LOG << "main";
    qnode->init(argc, argv);
    /***********ui*************/
   T3MainController *mc = new T3MainController();
   mc->run();

    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

    delete mc;

	return result;
}
