#ifndef HILL_CLIMBING_H_INCLUDED
#define HILL_CLIMBING_H_INCLUDED

float calculaPerturbacao (float r);

float calculaSolucaoInicial(float min, float max);

/* Função Objetivo: f(x) = x² */
float objetivoQuadratico (float x);
float SteepestAscent_Quadratica(float min, float max, float ruido);

/* Função Objetivo: Ackley Function */
float objetivoAckley(float x, float y);
float SteepestAscent_Ackley(float min, float max, float ruido);

#endif // HILL_CLIMBING_H_INCLUDED
