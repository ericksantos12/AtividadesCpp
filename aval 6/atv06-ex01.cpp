/*
! Faça um programa com menu de três opções (1-ler linha, 2- mostrar e 3- sair), contendo um STRUCT para cadastrar o nome, a idade, o sexo, salário e salarioNovo de pelo menos duas pessoas. Crie um ponteiro para manipular o STRUCT. O programa deverá conter as seguintes sub rotinas abaixo: (use switch case )

* a) void NovaLinhaStruct ( ) 
* b) void listarLinhasStruct ( )
* c) ler_idade ( )
* d) ler_sexo ( )
* e) ler_nome ( )
* f) ler_salario ( )
* g) getAumento ( double * salario ) // aumento de 10% sobre o salário digitado

*/

#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
using namespace std;

struct colaborador
{
    string nome[5];
    int idade[5];
    string sexo[5];
    double salario[5];
    double salarioNovo[5];
} cadastro;

struct colaborador * p_cadastro = &cadastro; // ponteiro pro struct
int tamanho = sizeof(p_cadastro->nome)/sizeof(string); // tamanho do primeiro vetor do struct

int ler_idade(){
    int idade;
    cout << "Insira a idade -> ";
    cin >> idade;
    return idade;
}

string ler_sexo(){
    char sexo;
    cout << "Insira o sexo (m ou f) -> ";
    cin >> sexo;

    // Operador ternário, serve como um if else reduzido. Nesta situação Converte o 'm' ou 'f' por extenso.
    return tolower(sexo) == 'm' ? "Masculino" : "Feminino";
    // Como usar: <CONDIÇÃO> ? <CASO VERDADEIRO> : <CASO FALSO>
}

string ler_nome(){
    string nome;
    cout << "Insira um nome -> ";
    getline(cin.ignore(), nome);
    return nome;
}

double ler_salario(){
    double salario;
    cout << "Insira o salario -> ";
    cin >> salario;
    return salario;
}

double getAumento (double * salario){
    return (*salario) * 1.10; // recebe um ponteiro e multiplica ele por 110%
}



void novaLinhaStruct(){
    char continuar;
    for (int i = 0; i < tamanho; i++)
    {
        cout << "Pessoa " << (i + 1) << " de " << tamanho << endl; // Mostra qual posição você está preenchendo
        p_cadastro->nome[i] = ler_nome(); // Usa os métodos para ler nas variáveis do ponteiro
        p_cadastro->idade[i] = ler_idade();
        p_cadastro->sexo[i] = ler_sexo();
        p_cadastro->salario[i] = ler_salario();
        p_cadastro->salarioNovo[i] = getAumento(&p_cadastro->salario[i]);


        if (i != tamanho - 1){ // Verifica se a posição atual não é a última, se não for, ele perguntará se deseja ou não continuar
            cout << "\nDeseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) != 's') break;
        }
        system("cls");
    }
    
}

void listarLinhasStruct(){

    /**
     * Esta parte do código é responsável por mostrar os valores de cada vetor do Struct usando o ponteiro
     * Ele tabula os valores se utilizando da biblioteca <iomanip> e as funções 'left' e 'setw()'
     * setw() é responsável por designar os espaços entre os elementos, basicamente a largura das células
     * left irá alinhar o texto à esquerda
     */

    const int largura = 10;

    cout << "|" << left << setw(largura) << "Nome" << "|";
    cout << left << setw(largura) << "Idade" << "|";
    cout << left << setw(largura) << "Sexo" << "|";
    cout << left << setw(largura) << "Salario" << "|";
    cout << left << setw(largura) << "Sal. Novo" << "|" << endl; // cria o cabeçalho da tabela

    for (int i = 0; i < tamanho; i++)
    {
        if (p_cadastro->nome[i].size() != 0){ // Verifica se o nome da atual posição é ou não nulo, caso não seja ele irá mostrar na tela
            cout << "|" << left << setw(largura) << p_cadastro->nome[i] << "|";
            cout << left << setw(largura) << p_cadastro->idade[i] << "|";
            cout << left << setw(largura) << p_cadastro->sexo[i] << "|";
            cout << left << setw(largura) << p_cadastro->salario[i] << "|";
            cout << left << setw(largura) << p_cadastro->salarioNovo[i] << "|" << endl;
        }
    }
    
}



int main(int argc, char const *argv[])
{
    int key;
    MENU:

    system("cls");
    cout << "Escolha uma das opcoes:\n1 -- Ler Linha\n2 -- Mostrar\n3 -- Sair\n> ";
    cin >> key;
    system("cls");

    switch (key)
    {
    case 1:
        novaLinhaStruct();
        break;
    case 2:
        listarLinhasStruct();
        break;
    case 3:
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
