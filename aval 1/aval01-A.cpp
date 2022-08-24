/*
Fazer o programa fonte de um algoritmo para exibir os vetores: string nome [] = {"Sara Lemes","Ricardo Jaf�"} , 
double salario [] = {12000, 10243.20} e int idade[]={30, 45}; O sal�rio dever� ser exibido com 10% de aumento. 
Implemente um menu de execu��o.
*/

#include "iostream"

using namespace std;

int main() 
{
  string nome[] = {"Sara Lemes", "Ricardo Jafé"};
  double salario[] = {12000, 10243.20};
  int idade[] = {30,45};
  int opcao = 0;

  while (true){
  	cout << "(1) Consultar os dados\n(0) Fechar Programa\n> ";
  	cin >> opcao;
  	
  	if (opcao == 1){
  		for(int i=0; i < 2; i++)
  		{
    		cout << "Nome: " << nome[i] << endl;
    		cout << "Idade: " << idade[i] << endl;
    		cout << "Salario: " << salario[i] * 1.1 << endl << endl;
  		}
	  }
	else {
		break;
	}
  }



}
