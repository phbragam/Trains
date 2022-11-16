#include "trem.h"
#include <QtCore>
#include <QDebug>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

// variáveis que indicam se o trem está numa possível zona crítica

// trem 1
bool t1z0 = false;
bool t1z1 = false;
bool t1z2 = false;
// trem 2
bool t2z4 = false;
bool t2z3 = false;
bool t2z0 = false;
// trem 3
bool t3z1 = false;
bool t3z5 = false;
//trem 4
bool t4z2 = false;
bool t4z3 = false;
bool t4z6 = false;
bool t4z5 = false;
// trem 5
bool t5z4 = false;
bool t5z6 = false;

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if(velocidade < 200){
            switch(ID){
            case 1:     //Trem 1
                if (y == 20 && x <440)
                    x+=10;
                else if (x == 440 && y < 140)
                    y+=10;
                else if (x > 170 && y == 140)
                    x-=10;
                else
                    y-=10;

                // para o trem 1, as zonas críticas são as 0, 2 e 1
                if(x == 440 && y < 140){
                    if(t1z0 == false){
                        mutex0.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 1: ENTROU na zona critica 0";
                        t1z0 = true;
                    }
                    else{
                        qDebug() << "trem 1: zona critica 0";
                    }
                } else{
                    if(t1z0 == true){
                        qDebug() << "trem 1: SAIU da zona critica 0";
                        mutex0.unlock();
                        qDebug() << "UNLOCK";
                        t1z0 = false;
                    }
                }


                if(y == 140 && x >= 310 && x <= 440){
                    if(t1z2 == false){
                        mutex2.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 1: ENTROU na zona critica 2";
                        t1z2 = true;
                    }
                    else{
                        qDebug() << "trem 1: zona critica 2";
                    }
                } else{
                    if(t1z2 == true){
                        qDebug() << "trem 1: SAIU da zona critica 2";
                        mutex2.unlock();
                        qDebug() << "UNLOCK";
                        t1z2 = false;
                    }
                }


                if(y == 140 && x > 170 && x <= 310){
                    if(t1z1 == false){
                        mutex1.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 1: ENTROU na zona critica 1";
                        t1z1 = true;
                    }
                    else{
                        qDebug() << "trem 1: zona critica 1";
                    }
                } else{
                    if(t1z1 == true){
                        qDebug() << "trem 1: SAIU da zona critica 1";
                        mutex1.unlock();
                        qDebug() << "UNLOCK";
                        t1z1 = false;
                    }
                }


                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2: //Trem 2
                if (y == 20 && x <710)
                    x+=10;
                else if (x == 710 && y < 140)
                    y+=10;
                else if (x > 440 && y == 140)
                    x-=10;
                else
                    y-=10;


                // para o trem 2, as zonas críticas são as 0, 3 e 4
                if(x == 440 && y < 140){
                    if(t2z0 == false){
                        mutex0.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 2: ENTROU na zona critica 0";
                        t2z0 = true;
                    }
                    else{
                        qDebug() << "trem 2: zona critica 0";
                    }
                } else{
                    if(t2z0 == true){
                        qDebug() << "trem 2: SAIU da zona critica 0";
                        mutex0.unlock();
                        qDebug() << "UNLOCK";
                        t2z0 = false;
                    }
                }


                if(y == 140 && x >= 440 && x <= 580){
                    if(t2z3 == false){
                        mutex3.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 2: ENTROU na zona critica 3";
                        t2z3 = true;
                    }
                    else{
                        qDebug() << "trem 2: zona critica 3";
                    }
                } else{
                    if(t2z3 == true){
                        qDebug() << "trem 2: SAIU da zona critica 3";
                        mutex3.unlock();
                        qDebug() << "UNLOCK";
                        t2z3 = false;
                    }
                }


                if(y == 140 && x >= 580 && x <= 710)
                {
                    if(t2z4 == false){
                        mutex4.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 2: ENTROU na zona critica 4";
                        t2z4 = true;
                    }
                    else{
                        qDebug() << "trem 2: zona critica 4";
                    }
                } else{
                    if(t2z4 == true){
                        qDebug() << "trem 2: SAIU da zona critica 4";
                        mutex4.unlock();
                        qDebug() << "UNLOCK";
                        t2z4 = false;
                    }
                }

                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 3: //Trem 3
                if (y == 140 && x <310)
                    x+=10;
                else if (x == 310 && y < 260)
                    y+=10;
                else if (x > 40 && y == 260)
                    x-=10;
                else
                    y-=10;

                // para o trem 3, as zonas críticas são as 1 e 5
                if(y == 140 && x >= 170 && x <= 310){
                    if(t3z1 == false){
                        mutex1.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 3: ENTROU na zona critica 1";
                        t3z1 = true;
                    }
                    else{
                        qDebug() << "trem 3: zona critica 1";
                    }
                } else{
                    if(t3z1 == true){
                        qDebug() << "trem 3: SAIU da zona critica 1";
                        mutex1.unlock();
                        qDebug() << "UNLOCK";
                        t3z1 = false;
                    }
                }


                if(x == 310 && y < 260){
                    if(t3z5 == false){
                        mutex5.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 3: ENTROU na zona critica 5";
                        t3z5 = true;
                    }
                    else{
                        qDebug() << "trem 3: zona critica 5";
                    }
                } else{
                    if(t3z5 == true){
                        qDebug() << "trem 3: SAIU da zona critica 5";
                        mutex5.unlock();
                        qDebug() << "UNLOCK";
                        t3z5 = false;
                    }
                }


                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 4: //Trem 4
                if (y == 140 && x <580)
                    x+=10;
                else if (x == 580 && y < 260)
                    y+=10;
                else if (x > 310 && y == 260)
                    x-=10;
                else
                    y-=10;

                // para o trem 4, as zonas críticas são as 2, 3, 6 e 5
                if(y == 140 && x >= 310 && x <= 440){
                    if(t4z2 == false){
                        mutex2.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 4: ENTROU na zona critica 2";
                        t4z2 = true;
                    }
                    else{
                        qDebug() << "trem 4: zona critica 2";
                    }
                } else{
                    if(t4z2 == true){
                        qDebug() << "trem 4: SAIU da zona critica 2";
                        mutex2.unlock();
                        qDebug() << "UNLOCK";
                        t4z2 = false;
                    }
                }


                if(y == 140 && x >= 440 && x <= 580){
                    if(t4z3 == false){
                        mutex3.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 4: ENTROU na zona critica 3";
                        t4z3 = true;
                    }
                    else{
                        qDebug() << "trem 4: zona critica 3";
                    }
                } else{
                    if(t4z3 == true){
                        qDebug() << "trem 4: SAIU da zona critica 3";
                        mutex3.unlock();
                        qDebug() << "UNLOCK";
                        t4z3 = false;
                    }
                }


                if(x == 580 && y < 260){
                    if(t4z6 == false){
                        mutex6.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 4: ENTROU na zona critica 6";
                        t4z6 = true;
                    }
                    else{
                        qDebug() << "trem 4: zona critica 6";
                    }
                } else{
                    if(t4z6 == true){
                        qDebug() << "trem 4: SAIU da zona critica 6";
                        mutex6.unlock();
                        qDebug() << "UNLOCK";
                        t4z6 = false;
                    }
                }

                if(x == 310 && y < 260){
                    if(t4z5 == false){
                        mutex5.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 4: ENTROU na zona critica 5";
                        t4z5 = true;
                    }
                    else{
                        qDebug() << "trem 4: zona critica 5";
                    }
                } else{
                    if(t4z5 == true){
                        qDebug() << "trem 4: SAIU da zona critica 5";
                        mutex5.unlock();
                        qDebug() << "UNLOCK";
                        t4z5 = false;
                    }
                }



                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 5: //Trem 5
                if (y == 140 && x <850)
                    x+=10;
                else if (x == 850 && y < 260)
                    y+=10;
                else if (x > 580 && y == 260)
                    x-=10;
                else
                    y-=10;

                // para o trem 5, as zonas críticas são as 4 e 6
                if(y == 140 && x >= 580 && x <= 710){
                    if(t5z4 == false){
                        mutex4.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 5: ENTROU na zona critica 4";
                        t5z4 = true;
                    }
                    else{
                        qDebug() << "trem 5: zona critica 4";
                    }
                } else{
                    if(t5z4 == true){
                        qDebug() << "trem 5: SAIU da zona critica 4";
                        mutex4.unlock();
                        qDebug() << "UNLOCK";
                        t5z4 = false;
                    }
                }


                if(x == 580 && y < 260){
                    if(t5z6 == false){
                        mutex6.lock();
                        qDebug() << "LOCK";
                        qDebug() << "trem 5: ENTROU na zona critica 6";
                        t5z6 = true;
                    }
                    else{
                        qDebug() << "trem 5: zona critica 6";
                    }
                } else{
                    if(t5z6 == true){
                        qDebug() << "trem 5: SAIU da zona critica 6";
                        mutex6.unlock();
                        qDebug() << "UNLOCK";
                        t5z6 = false;
                    }
                }


                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            default:
                break;
            }
            msleep(velocidade);
        }
    }
}

void Trem::setSpeed(int value){

    this->velocidade = 250 - value;
}




