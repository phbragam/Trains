#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>

inline QMutex mutex0;
inline QMutex mutex1;
inline QMutex mutex2;
inline QMutex mutex3;
inline QMutex mutex4;
inline QMutex mutex5;
inline QMutex mutex6;


/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    void run();        //função a ser executada pela thread
    void setSpeed(int);


//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
