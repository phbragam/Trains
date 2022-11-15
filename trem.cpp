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

bool t5z4 = false;

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if(velocidade != 200){
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
                if(x == 440 && y < 140)
                    qDebug() << "trem 1: zona critica 0";

                if(y == 140 && x >= 310 && x <= 440)
                    qDebug() << "trem 1: zona critica 1";

                if(y == 140 && x > 170 && x <= 310)
                    qDebug() << "trem 1: zona critica 2";

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
                if(x == 440 && y < 140)
                    qDebug() << "trem 2: zona critica 0";

                if(y == 140 && x >= 440 && x <= 580)
                    qDebug() << "trem 2: zona critica 3";

                if(y == 140 && x >= 580 && x <= 710)
                    qDebug() << "trem 2: zona critica 4";

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
                if(y == 140 && x >= 170 && x <= 310)
                    qDebug() << "trem 3: zona critica 1";

                if(x == 310 && y < 260)
                    qDebug() << "trem 3: zona critica 5";

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

                // para o trem 4, as zonas críticas são as 2, 3 e 6
                if(y == 140 && x >= 310 && x <= 440)
                    qDebug() << "trem 4: zona critica 2";

                if(y == 140 && x >= 440 && x <= 580)
                    qDebug() << "trem 4: zona critica 3";

                if(x == 580 && y < 260)
                    qDebug() << "trem 4: zona critica 6";


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

//                bool t5z4 = false;
                // para o trem 5, as zonas críticas são as 4 e 6
                if(y == 140 && x >= 580 && x <= 710){
                    if(t5z4 == false){
                        qDebug() << "trem 5: ENTROU na zona critica 4";
                        t5z4 = true;
                    }
                    else{
                        qDebug() << "trem 5: zona critica 4";
                    }
                } else{
                    if(t5z4 == true){
                        qDebug() << "trem 5: SAIU da zona critica 4";
                        t5z4 = false;
                    }
                }


                if(x == 580 && y < 260)
                    qDebug() << "trem 5: zona critica 6";

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




