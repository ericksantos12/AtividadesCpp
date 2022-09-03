// l) Elaborar um programa que efetue a leitura de três valores (A, B e C) e apresente como resultado final à soma dos quadrados dos três valores lidos.
#include <iostream>
#include <math.h>
using namespace std;

float somaQuadrado(float a, float b, float c);

int main(int argc, char const *argv[])
{
    float valorA = 0;
    float valorB = 0;
    float valorC = 0;

    cout << "Insira o primeiro valor: ";
    cin >> valorA;
    cout << "Insira o segundo valor: ";
    cin >> valorB;
    cout << "Insira o terceiro valor: ";
    cin >> valorC;

    cout << "A soma dos quadrados dos tres valores e: " << somaQuadrado(valorA, valorB, valorC) << endl;
    return 0;
}

float somaQuadrado(float a, float b, float c){
    return pow(a, 2) + pow(b, 2) + pow(c, 2);
}