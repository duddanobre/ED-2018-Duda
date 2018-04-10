#include <lib/pen.h>
void fgelo(Pen &p, int lado){
    int angulo = 72;
         if(lado < 1)
             return;
        for(int i=0; i<5;i++){
              p.setBackColor(255,255,255);
              p.setColor(30,144,255);
              p.walk(lado);
              fgelo(p, lado * 0.35);
              p.walk(-lado);
              p.right(angulo);


        }
}

void circulos(Pen& p, int lado){
    if(lado < 1)
          return;
    for(int i=0;i<6;i++){
        p.setBackColor(255,240,245);
        p.setColor(255,165,0);
          p.circle(lado);
          p.left(60);
          p.up();
          p.walk(lado);
          p.down();
          circulos(p, lado*2/6);
          p.up();
          p.walk(-lado);
          p.down();
     }

}

void trigof(Pen &p, int lado){
    int dec=3;
    int angulo=40;
    if(lado<1)
        return;

    for(int i=0;i<4;i++){
        p.setBackColor(255,255,255);
        p.setColor(218,165,32);
        p.walk(lado);
        p.right(angulo);
        trigof(p,lado/dec);
        p.left(2*angulo);
        trigof(p,lado/dec);
        p.right(angulo);
    }
    p.walk(-lado*4);
}
void fractalG(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(500,400);
    p.setThickness(1);
    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    circulos(p,200);
   // fgelo(p, 100);
   //trigof(p, 100);

    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractalG();
    return 0;
}
