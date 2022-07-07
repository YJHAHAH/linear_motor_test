#ifndef STATUSOBSERVE_H
#define STATUSOBSERVE_H

#include <QObject>
#include "board.h"
#include <QThread>

class statusObserve : public QObject
{
    Q_OBJECT
public:
    explicit statusObserve(QObject *parent = nullptr,board* board=nullptr);
    void status_update();
    bool stop_flag=false;
    ~statusObserve();
private:
     board* myboard;

signals:
     void  status(double pos,int status_word);

};

#endif // STATUSOBSERVE_H
