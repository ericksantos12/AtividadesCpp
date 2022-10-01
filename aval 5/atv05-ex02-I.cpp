/*
! II - Escolha dois dos três exercícios para utilizar funções que tenham argumentos como ponteiros. Faça os programas com estrutura case, menu , funções de entrada, de cálculos e de saída. 
! a) Equação do Segundo Grau b) Triângulo Heron c) Cálculo da área de um círculo. 
*/

// equação do segundo grau

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

struct coeficientes
{
    float a;
    float b;
    float c;
} coeficientes;
struct coeficientes *p_coef = &coeficientes;


void lerValores(){
    cout << "Insira o valor do coeficiente A" << endl;
    cin >> p_coef->a;
    cout << "Insira o valor do coeficiente B" << endl;
    cin >> p_coef->b;
    cout << "Insira o valor do coeficiente C" << endl;
    cin >> p_coef->c;

    cout << "-- Valores Inseridos --" << endl;
    
}

void calcularBhaskara(float *a, float *b, float *c){
    float delta;
    float x1;
    float x2;
    delta = pow((*b), 2) - 4 * (*a) * (*c);
    
    if (delta < 0)
    {
        cout << "Nao existem raizes reais." << endl;
    } else {
        x1 = (- (*b) + sqrt(delta))/2 * (*a);
        x2 = (- (*b) - sqrt(delta))/2 * (*a);
        
        cout << "\nOs resultados sao:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    
    
}

int main(int argc, char const *argv[])
{


    int key;
    MENU:
    system("cls");

    cout << "Selecione uma das opcoes:\n1 -- Ler Valores\n2 -- Calcular Equacao do Segundo Grau\n0 -- Sair\n> ";
    cin >> key;

    system("cls");
    switch (key)
    {
    case 1:
        lerValores();
        break;
    case 2:
        calcularBhaskara(&p_coef->a, &p_coef->b, &p_coef->c);
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
