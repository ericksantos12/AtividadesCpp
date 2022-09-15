/*
* a) Elaborar um programa de computador que efetue a leitura de quatro valores inteiros (variáveis A, B, C e D). Ao final o programa deve apresentar o resultado do produto (variável P) do primeiro com o terceiro valor, e o resultado da soma (variável S) do segundo com o quarto valor.
! 1. Os dados de entrada e saída deverão ser armazenados em um struct com várias colunas; 
! 2. Deverá conter menu com switch case, funções para leitura dos dados de entrada e as respectivas funções para calcular os dados de saída; 
! 3. Tanto os dados de entrada quanto os dados de saída deverão ser armazenados dentro de structs.
*/

#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

struct Variaveis
{
    int A;
    int B;
    int C;
    int D;
    
    int P;
    int S;
};

struct Variaveis valor;

void lerInteiros(){
    system("cls");
    cout << "Insira os valores das variaveis A, B, C e D respectivamente, separando por espacos:" << endl;
    cin >> valor.A >> valor.B >> valor.C >> valor.D;
    cout << "---- Valores lidos! ----" << endl;
    system("pause");
}

void produto(){
    system("cls");
    valor.P = valor.A * valor.C;
    cout << "O produto de " << valor.A << " por " << valor.C << " e: " << valor.P << endl;
    system("pause");
}

void soma(){
    system("cls");
    valor.S = valor.B + valor.D;
    cout << "A soma de " << valor.B << " por " << valor.D << " e: " << valor.S << endl;
    system("pause");
}

int main(int argc, char const *argv[])
{
    int key;

    MENU:
    system("cls"); // Limpa Tela

    cout << "Escolha uma das opcoes:\n1 --- Ler Valores\n2 --- Mostrar Produto (1o e 3o valor)\n3 --- Mostrar Soma (2o e 4o valor)\n0 --- Fechar Programa \n> ";
    cin >> key;

    switch (key)
    {
    case 1:
        lerInteiros();
        break;
    case 2:
        produto();
        break;
    case 3:
        soma();
        break;
    
    case 0:
        system("cls");
        cout << "O programa foi encerrado." << endl;
        exit(0);
        break;
    default:
        break;
    }

    goto MENU;
    return 0;
}

