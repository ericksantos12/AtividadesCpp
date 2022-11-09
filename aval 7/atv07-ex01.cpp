#include <iostream>
#include <cstdlib>
#define MAX 3
using namespace std;

/*
? Faça  um  programa  estruturado  para  controlar  uma  pilha  com  arranjo simples contendo os atributos: IDADE, NOME e SALÁRIO.  
? O código da LIFO deverá conter as seguintes funções obrigatórias:
* A.push() para empilhar o registro
* B.pop() para remover registros
* C.int mostrar() para mostrar os registros da LIFO
* D.bool cheia() verificar se a LIFO está cheia
* E.bool vazia() verificar se a LIFO está vazia
* F.int  tela  ()  exibe  a  tela  e  armazena  o  valor  da  opção  de  menu selecionada
* G.void Controle() controla o menu de controle da LIFO
*/



typedef struct lifo pilha;

struct lifo {
  int topo;
  string nome[MAX];
  int idade[MAX];
  double salario[MAX];
};


bool vazia(pilha p){
  return p.topo == -1 ? true : false;
}
bool cheia(pilha p){
  return p.topo == MAX - 1 ? true : false;
}

pilha push(int idade, string nome, double salario, pilha p){

  if (cheia(p) == true){
    cout << "[!] A pilha esta cheia" << endl;
    return p;
  }

  p.topo++;
  p.idade[p.topo] = idade;
  p.nome[p.topo] = nome;
  p.salario[p.topo] = salario;
  
  cout << "[!] Registro Empilhado" << endl;

  return p;
}

pilha pop(pilha p){

  if(vazia(p) == true){
    cout << "[!] A pilha ja esta vazia" << endl;
    system("pause");
    return p;
  }

  cout << "[!] Removendo o registro " << p.topo << " " << p.nome[p.topo] << endl << endl;

  p.idade[p.topo] = '\0';
  p.nome[p.topo] = '\0';
  p.salario[p.topo] = '\0';
  p.topo--;
  return p;
}

void mostrar(pilha p){
  if(vazia(p) == true){
    cout << "[!] A pilha esta vazia" << endl;
  } else {

    cout << "-- Registros --" << endl;
    for(int i = 0; i < p.topo + 1; i++){
      cout << "Cadastro: " << i + 1 << endl;
      cout << "Idade: " << p.idade[i] << endl;
      cout << "Nome: " << p.nome[i] << endl;
      cout << "Salario: " << p.salario[i] << endl << endl;
    }

  }
}

int tela(){
  int opcao = 0;

  cout << "--|Pilhas|-- \n1 -- Empilhar registro \n2 -- Remover registro \n3 -- Mostrar registros \n0 -- Sair \n> ";
  cin >> opcao;
    
  return opcao;
}

void controle(){

    pilha cadastro;
    cadastro.topo = - 1;
    string nome = "";
    int idade = 0;
    double salario = 0;
  
  MENU:

    system("cls");
    int key = tela();
    system("cls");

    switch(key){
      case 1:
        cout << "Insira o nome: ";
        cin >> nome;
        cout << "Insira a Idade: ";
        cin >> idade;
        cout << "Insira o Salario: ";
        cin >> salario;

        cadastro = push(idade, nome, salario, cadastro);
        break;
      
      case 2:
        cadastro = pop(cadastro);
        break;
      
      case 3:
        mostrar(cadastro);
        break;
      
      case 0:
        cout << "Encerrando o programa" << endl;
        exit(0);
        break;
    }
    system("pause");
  goto MENU;
  
}

int main() {
  controle();
}

