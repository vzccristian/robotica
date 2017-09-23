#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include <thread>
#include <QLCDNumber>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "hilocontador.h"
#include <mutex> 
#include <sys/syscall.h>
#include <sys/types.h>
#include <QDebug>

using namespace std;
class ejemplo1 : public QWidget, public Ui_ContadordeCristian {
Q_OBJECT

private:
    hilocontador hilo;
    int valor=0; //VALOR DEL CONTADOR
    bool started=false;
    std::mutex mtx; 
    //hilocontador* hilo; //USADO EN EJEMPLO BASICO.
    //QTimer *timer; //USANDO EN EJEMPLO CON QTIMER
    //std::thread t[10]; //USADO EN EJEMPLO ARRAYS
    
public:
    ejemplo1();
    //static int cnt1; //USANDO EN DISTINTOS EJEMPLOS ANTERIORES
    //void contar();
    void tick();
    virtual ~ejemplo1();

    
public slots:
    void doButtonStart();
	void doButtonPause();
    void doButtonSetPeriod();
    void doButtonRestart();
    //void mostrar(int value);
};

#endif // ejemplo1_H
