/*
 * Copyright 2017
 * Cristian Vázquez Cordero
 */

#include "ejemplo1.h"

//int ejemplo1::cnt1 = 0; Usando en ejemplos arrays.

/*
 * Constructor 
 */
ejemplo1::ejemplo1() : Ui_ContadordeCristian()
{
    // __________ INFO HILOS _______________
    pid_t tid;
    tid = syscall(SYS_gettid);
    //qDebug() <<"Padre:"<< tid;

    //____________ QT _____________________
    setupUi(this);
    lcdNumber->setDigitCount(6);
    connect(buttonPause, SIGNAL(clicked()), this, SLOT(doButtonPause()));
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(doButtonStart()));
    connect(buttonSetPeriod, SIGNAL(clicked()), this, SLOT(doButtonSetPeriod()));
   connect(buttonRestart, SIGNAL(clicked()), this, SLOT(doButtonRestart()));
    show();

    // ____________ BASICO _____________
    // USANDO LA CLASE HILO CONTADOR (QTHREAD)
    // hilo = new hilocontador();
     //connect(hilo, SIGNAL(newValue(int)), this, SLOT(mostrar(int)));
    // hilo->start();

    // _______PRIMERA PARTE (QTIMER)_____________
    // 	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
    //  timer = new QTimer(this);
    //  connect(timer, SIGNAL(timeout()), this, SLOT(contar()));
    //  timer->start(1000);


    //________SEGUNDA PARTE_____________
    // COMO CREAR UN HILO CON FUNCION LAMBDA.
    // T1 YA ESTA CREADO, TIENE UNA DIRECCION DE MEMORIA, PERO PARA PODER ASIGNARLE EL HILO CREADO CON LAMBA
    // USAMOS MOVE PARA MOVER EL PUNTERO DE T1 A DONDE QUIERA QUE APUNTE EL CONTENIDO DE LA FUNCION LAMBDA
    // t1 = std::move ( std::thread ([]() {while(1){qDebug() << "hilo"; sleep(1); }}));

    //_______TERCERA PARTE (ARRAY DE 10 HILOS)_____________
    // Creo un hilo que llama a contar. En contar se ejecutan 10 hilos que NO esperan por el hilo que los llama
    // porque de ser así, no podría mostrar el contador gráfico
    //std::thread aux(&ejemplo1::contar,this);
    //aux.join();

    //______ CUARTA PARTE (correo pablo) _____________
    //std::thread aux(&ejemplo1::contar2,this);
    //aux.join();
}

ejemplo1::~ejemplo1()
{}


// void ejemplo1::contar() {
//     //_______ARRAY DE 10 HILOS______________-
//     pid_t tid;
//     tid = syscall(SYS_gettid);
//     qDebug() <<"Contar:"<< tid;
//     int i=0;
//     while (i<10) {
//         t[i] = std::move ( std::thread ([i,&cnt1,this]()  {
//             pid_t tid;
//             tid = syscall(SYS_gettid);
//             qDebug() <<"Contador["<<i<<"]:"<< tid;
//             // qDebug() <<"["<<i<<"]"<<"While: "<<cnt1<<(cnt1/10);
//             while (cnt1/10!=i) {
//                 sleep(1);
//                 if (i==10)
//                     std::terminate();
//             };
//             while (cnt1/10==i) {
//                 // qDebug() << "Soy hilo "<<i<<" n:"<< cnt1;
//                 std::string s = std::to_string(cnt1);
//                 std::string s1 = std::to_string(i);
//                 std::string s2 = s1+"-"+s;
//                 // qDebug(s2.c_str());
//                 QString s3 = QString::fromStdString(s2);
//                 lcdNumber->display(s3);
//                 cnt1++;
//                 //sleep(1);
//             }
//         }));
//         i++;
//     }
//     qDebug() <<"Muere Contar:"<< tid;
// //     for (auto&& h:t)
// //         h.join();
// }


/*
 * Tick. Recibe la señal para aumentar el valor del contador.
 */
void ejemplo1::tick() {
    mtx.lock();
    valor++;
    mtx.unlock();
    lcdNumber->display(valor);
    //qDebug()<<valor;
}

/*
 * Acción de botón "Start".
 */
void ejemplo1::doButtonStart()
{
    //qDebug() << "Start";
    if (!started) {
        //qDebug() << "Inicio";
        started=true;
        std::thread t4 = std::move(std::thread(&hilocontador::run, &hilo, std::bind(&ejemplo1::tick, this)));
        t4.detach();
    } else 
        hilo.start();
    buttonStart->setDisabled(1);
    buttonPause->setEnabled(1);

}


/*
 * Acción de botón "Pause".
 */
void ejemplo1::doButtonPause()
{
    //qDebug() << "Pause";
    hilo.pause();
    buttonStart->setEnabled(1);
    buttonPause->setDisabled(1);

}

/*
 * Acción de botón "SetPeriod".
 */
void ejemplo1::doButtonSetPeriod()
{
    //qDebug() << "SetPeriod" << linePeriod->text();
    bool convertOK;
    unsigned long int n = linePeriod->text().toULong(&convertOK);
    if(convertOK) {
        hilo.setPeriod(n);
        QString result = QString::fromStdString("");
        lineError->setText(result);
        std::string sP = std::to_string(n);
        std::string sOk = "Period: "+sP+" ms.";
        result = QString::fromStdString(sOk);
        lineOk->setText(result);
    }
    else {
        //qDebug() << "error";
        QString result = QString::fromStdString("");
        lineOk->setText(result);
        result = QString::fromStdString("(Error)");
        lineError->setText(result);
    }

}

/*
 *  * Acción de botón "Restart".
 */
void ejemplo1::doButtonRestart()
{
    hilo.pause();
    mtx.lock();
    valor=0;
    lcdNumber->display(valor);
    mtx.unlock();
    hilo.start();
}


// void ejemplo1::mostrar(int value)
// {
// 
//     //qDebug() << " mostrar "<<value;
//     //lcdNumber->display(value);
// 
// }








