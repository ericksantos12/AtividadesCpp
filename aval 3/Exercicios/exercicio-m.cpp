// m) Elaborar um programa que efetue a leitura de três valores (A,B e C) e apresente como resultado final o quadrado da soma dos três valores lidos.
#include <iostream>
#include <math.h>
using namespace std;

float quadradoSoma(float a, float b, float c);

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

    cout << "O quadrado da soma dos tres valores e: " << quadradoSoma(valorA, valorB, valorC) << endl;
    return 0;
}

float quadradoSoma(float a, float b, float c){
    return pow((a + b + c), 2);
}