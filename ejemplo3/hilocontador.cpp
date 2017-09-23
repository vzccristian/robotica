/*
 * Copyright 2017
 * Cristian Vázquez Cordero
 */

#include "hilocontador.h"

hilocontador::hilocontador(): QThread()
{}

hilocontador::~hilocontador()
{}


void hilocontador::run(std::function<void()> tick)
{
    while (1) {
    while (!stop) {
        tick();
        usleep(hilocontador::period*1000);
    }}
}

void hilocontador::start()
{
    mtx.lock();
    stop=false;
    mtx.unlock();
    //qDebug() << "hilo::start";
}


void hilocontador::pause()
{
    mtx.lock();
    stop=true;
    mtx.unlock();
    //qDebug() << "hilo::pause";

}

void hilocontador::setPeriod(int millis)
{
    //qDebug() << "hilo:setPeriod";
    mtx.lock();
    hilocontador::period=millis;
    mtx.unlock();
}
