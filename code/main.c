#include <stdio.h>
#include <stdlib.h>
#include "Hill_Climbing.h"

int main()
{
    float Q, A;
    FILE *arqQuadratica, *arqAckley;

    arqQuadratica = fopen("Solucoes-Quadratica.txt", "a");
    arqAckley = fopen("Solucoes-Ackley.txt", "a");

    /* Função Objetivo: Quadrática - F(x) = x² */
    Q = SteepestAscent_Quadratica(-10, 10, 0.5);
    fprintf(arqQuadratica, "Execucao - Solucao: %f\n", Q);

    /* Função Objetivo: Ackley Function */
    A = SteepestAscent_Ackley (-5, 5, 0.5);
    fprintf(arqAckley,"Execucao - Solucao: %f\n", A);

    fclose(arqQuadratica);
    fclose(arqAckley);

    return 0;
}
