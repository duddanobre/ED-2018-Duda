#include <lib/pen.h>

void arvorea(Pen& p, int lado){
    float ang = 27;
    if(lado<10)
        return;
    p.setColor(255,0,255);//magenta
    p.setBackColor(234,234,174);// goldenrod médio
    p.walk(lado);
    p.left(ang);
    arvorea(p, lado - 10);
     p.down();
     p.setColor(255,0,255);
    p.setThickness(10);
    p.right(ang);
    arvorea(p, lado - 10);
    p.right(ang);
    arvorea(p, lado - 10);
    p.left(ang);
    p.walk(-lado);
    p.setColor(151,105,79);//tan escuro
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500

    p.setXY(400,590);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    int lado = 100;
    arvorea(p, lado);

    //espera clicar no botao de fechar
    p.wait();

}

int main7(){
  fractal();

return 0;
}



