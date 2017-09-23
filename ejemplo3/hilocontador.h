#ifndef hilocontador_H
#define hilocontador_H

#include <QtGui>
#include <QLCDNumber>
#include <functional>
#include <mutex>          // std::mutex


/*
 * Clase Hilocontador - Mantiene el periodo y envía la señal a clase ejemplo1.
 */
class hilocontador : public QThread 
{
Q_OBJECT
private:
    int period=1000; /* Periodo por defecto: 1000ms */
    bool stop=false;
    std::mutex mtx;     
public:
    hilocontador();
    void run(std::function<void()> tick);
    virtual ~hilocontador();
signals:
public slots:
	void start();
    void pause();
    void setPeriod(int millis);
};

#endif // HILOCONTADOR_H
