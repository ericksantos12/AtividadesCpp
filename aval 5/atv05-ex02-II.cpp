/*
! II - Escolha dois dos três exercícios para utilizar funções que tenham argumentos como ponteiros. Faça os programas com estrutura case, menu , funções de entrada, de cálculos e de saída. 
! a) Equação do Segundo Grau b) Triângulo Heron c) Cálculo da área de um círculo. 
*/

// area de um circulo

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double const pi = 3.14159265359;

float * lerValor(){
    static float x;

    cout << "Insira o valor do comprimento do circulo: ";
    cin >> x;
    cout << "-- Valores Inseridos --" << endl;
    return &x;
}

void calcularArea(float *x){
    float raio = *x / (2*pi);
    float area = pi * pow(raio, 2);

    cout << "A area do circulo e de: " << area << endl;
}

int main(int argc, char const *argv[])
{

    float * comprimento;

    int key;
    MENU:
    system("cls");

    cout << "Selecione uma das opcoes:\n1 -- Ler Valores\n2 -- Calcular Area do Circulo\n0 -- Sair\n> ";
    cin >> key;

    system("cls");
    switch (key)
    {
    case 1:
        comprimento = lerValor();
        break;
    case 2:
        calcularArea(comprimento);
        break;

    case 0:
        cout << "O programa foi encerrado!" << endl;
        exit(0);
        break;


    default:
        break;
    }
    system("pause");
    goto MENU;
    return 0;
}