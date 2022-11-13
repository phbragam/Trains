#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
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
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




