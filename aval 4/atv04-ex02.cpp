/*
* b) Ler o valor correspondente ao salário mensal (variável SM) de um trabalhador e também o valor do percentual de reajuste (variável PR) a ser atribuído. Apresentar o valor do novo salário (variável NS).
! 1. Os dados de entrada e saída deverão ser armazenados em um struct com várias colunas; 
! 2. Deverá conter menu com switch case, funções para leitura dos dados de entrada e as respectivas funções para calcular os dados de saída; 
! 3. Tanto os dados de entrada quanto os dados de saída deverão ser armazenados dentro de structs.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Salario {
    double SM;
    double PR;
    double NS;
};

struct Salario colab;

void lerValores(){
    system("cls");
    cout << "Infome o valor do salario mensal -> ";
    cin >> colab.SM;
    cout << "Informe o percentual de reajuste -> ";
    cin >> colab.PR;
    colab.PR = (colab.PR / 100) + 1;
    cout << "--- Valores Inseridos ---" << endl;
    system("pause");
}

void mostrarReajuste(){
    system("cls");
    colab.NS = colab.SM * colab.PR;
    cout << "Salario: " << colab.SM << "\nPercentual de Reajuste: " << (colab.PR - 1) * 100 << "% \nNovo Salario: " << colab.NS << endl;
    
    system("pause");
}


int main(int argc, char const *argv[])
{
    int key = 0;

    MENU:
    system("cls");
    cout << "Escolha uma das opcoes:\n1 --- Inserir Valores\n2 --- Exibir Novo Salario\n0 --- Fechar Programa\n> ";
    cin >> key;

    switch (key)
    {
    case 1:
        lerValores();
        break;
    
    case 2:
        mostrarReajuste();
        break;
    
    case 0:
        system("cls");
        cout << "O programa foi encerrado!" << endl;
        exit(0);
        break;
    
    default:
        break;
    }

    goto MENU;
    return 0;
}

