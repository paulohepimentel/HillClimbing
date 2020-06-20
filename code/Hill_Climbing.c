#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define iteracoes 10 /* O numero maximo de iterações será 10 */
#define amostras 30 /* O numero de amostras será 30 */

float calculaPerturbacao (float r){

    float p;
    p = ((r - (-r)) * ((float)rand()/RAND_MAX) + (-r));
    return p;
}

float calculaSolucaoInicial(float min, float max){

    float s;
    s = ((max - min) * ((float)rand()/RAND_MAX) + min);
    return s;
}

/************************************ Função Quadrática ************************************/
float objetivoQuadratico (float x){

    x = pow(x, 2);
    return x;
}

float SteepestAscent_Quadratica(float min, float max, float ruido){

    int i, j;
    float S, R, W;

    srand((unsigned)time(NULL));

    S = calculaSolucaoInicial(min, max);

    for(i=0; i<iteracoes; i++){
        R = S + calculaPerturbacao(ruido);

        for(j=0; j<amostras; j++){
            W = S + calculaPerturbacao(ruido);

            if(objetivoQuadratico(W) < objetivoQuadratico(R)){ /* Minimização */
                R = W;
            }
        }

        if(objetivoQuadratico(R) < objetivoQuadratico(S)){
            S = R;
        }
    }

    //printf("Valor final: %.2f\nSolucao final: %f\n\n\n", S, objetivoQuadratico(S));
    return objetivoQuadratico(S);
}


/************************************ Função de Ackley ************************************/
float objetivoAckley(float x, float y){

    float s;

    s = -20 * exp(-0.2 * sqrt(0.5*(pow(x,2) + pow(y,2))));
    s = s - exp(0.5 * (cos(2*M_PI*x) + cos(2*M_PI*x))) + M_E + 20;

    return s;
}

float SteepestAscent_Ackley(float min, float max, float ruido){

    int i, j;
    float Sx, Sy, Rx, Ry, Wx, Wy;

    srand((unsigned)time(NULL));

    Sx = calculaSolucaoInicial(min, max);
    Sy = calculaSolucaoInicial(min, max);
    //printf("Valor inicial: x= %.2f\ty= %.2f\nSolucao inicial: x,y= %.3f\n", Sx, Sy, objetivoAckley(Sx, Sy));

    for(i=0; i<iteracoes; i++){
        Rx = Sx + calculaPerturbacao(ruido);
        Ry = Sy + calculaPerturbacao(ruido);

        for(j=0; j<amostras; j++){
            Wx = Sx + calculaPerturbacao(ruido);
            Wy = Sy + calculaPerturbacao(ruido);

            if(objetivoAckley(Wx, Wy) < objetivoAckley(Rx, Ry)){ /* Minimização */
                Rx = Wx;
                Ry = Ry;
            }
        }

        if(objetivoAckley(Rx, Ry) < objetivoAckley(Sx, Sy)){
            Sx = Rx;
            Sy = Ry;
            printf("Valor intermediario %d: x= %f\ty= %f\nSolucao intermediaria: x,y= %f\n\n", i, Sx, Sy, objetivoAckley(Sx, Sy));
        }
    }

    printf("Valor final: x= %.2f\ty= %.2f\nSolucao final: x,y= %.3f\n", Sx, Sy, objetivoAckley(Sx, Sy));
    return objetivoAckley(Sx, Sy);
}
