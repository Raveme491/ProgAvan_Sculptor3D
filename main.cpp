#include "Sculptor.h"

int main(void){

    Sculptor semaforo(70,120,120);

    semaforo.setColor(0.5,0.5,0.5,1);
    semaforo.putSphere(0,50,4,52);
    semaforo.setColor(0,0,0,1); // CURVA D0 POSTE
    semaforo.cutSphere(0,50,0,50);
    semaforo.cutBox(0,70,0,120,7,70); // CORTE DA CURVA DO POSTE
    semaforo.cutBox(0,70,0,120,0,3);
    semaforo.cutBox(0,70,0,50,0,70);

    semaforo.setColor(1,0,0,1); // ESFERA VERMELHA
    semaforo.putSphere(8,110,11,5);

    semaforo.setColor(1,1,0,0.5); // ESFERA AMARELA
    semaforo.putSphere(8,98,11,5);

    semaforo.setColor(0,1,0,0.5); // ESFERA VERDE
    semaforo.putSphere(8,86,11,5);

    semaforo.cutBox(0,17,0,120,0,10); // CORTE DAS ESFERAS

    semaforo.setColor(0,0,0,1); // CAIXA DO SEMAFORO
    semaforo.putBox(0,17,80,117,7,13);

    semaforo.setColor(0.5,0.5,0.5,1); // BARRA DO SEMAFORO
    semaforo.putBox(6,9,82,115,3,7);

    semaforo.setColor(0.5,0.5,0.5,1); // BARRA HORIZONTAL
    semaforo.putBox(6,50,97,100,3,7);

    semaforo.setColor(0.5,0.5,0.5,1); // BARRA VERTICAL
    semaforo.putBox(48,53,0,100,3,7);

    semaforo.setColor(0,0.4,0,1); // GRAMA
    semaforo.putBox(43,55,2,3,0,10);

    semaforo.setColor(0.36,0.25,0.2,1); // TERRA
    semaforo.putBox(43,55,0,2,0,10);

    semaforo.setColor(0,0,0,1); // Asfalto
    semaforo.putBox(0,42,0,2,0,120);
    semaforo.setColor(1,1,1,1);
    semaforo.putBox(20,22,1,2,27,37);
    semaforo.putBox(20,22,1,2,39,49);
    semaforo.putBox(20,22,1,2,51,61);
    semaforo.putBox(20,22,1,2,63,73);
    semaforo.putBox(20,22,1,2,75,85);
    semaforo.putBox(20,22,1,2,87,97);
    semaforo.putBox(20,22,1,2,99,109);
    semaforo.putBox(20,22,1,2,111,120);

    semaforo.setColor(1,1,1,1); // Faixa de pedestre;
    semaforo.putBox(20,22,1,2,27,37);
    semaforo.putBox(20,22,1,2,27,37);
    semaforo.putBox(2,5,1,2,4,25);
    semaforo.putBox(7,10,1,2,4,25);
    semaforo.putBox(12,15,1,2,4,25);
    semaforo.putBox(17,20,1,2,4,25);
    semaforo.putBox(22,25,1,2,4,25);
    semaforo.putBox(27,30,1,2,4,25);
    semaforo.putBox(32,35,1,2,4,25);
    semaforo.putBox(37,40,1,2,4,25);
    semaforo.putBox(42,44,0,3,0,25); 

    semaforo.setColor(1,1,0,1); // Meio fio;
    semaforo.putBox(42,44,0,4,25,35);
    semaforo.putBox(42,44,0,4,37,47);
    semaforo.putBox(42,44,0,4,49,59);
    semaforo.putBox(42,44,0,4,51,61);
    semaforo.putBox(42,44,0,4,63,73);
    semaforo.putBox(42,44,0,4,75,85);
    semaforo.putBox(42,44,0,4,87,97);
    semaforo.putBox(42,44,0,4,99,109);
    semaforo.putBox(42,44,0,4,111,120);
    semaforo.setColor(0,0,0,1);
    semaforo.putBox(42,44,0,2,0,120);


    semaforo.setColor(0.5,0.5,0.5,1);
    semaforo.putBox(44,55,0,3,10,120);

    semaforo.writeOFF("semaforo.off");

  return 0;
}
