/* 
Fazer um programa que leia através do teclado dados de clientes para um cadastro de um site qualquer, 
os dados deverão ser armazenados em vetores: nome, cpf, endereço, email e telefone. Permitir a leitura de no máximo 4 registros apenas
*/

#include "iostream"
using namespace std;

int main()
{
    int const n = 4;
    string nome[n];
    string cpf[n];
    string endereco[n];
    string email[n];
    string telefone[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nome: ";
        cin >> nome[i];
        cout << "CPF: ";
        cin >> cpf[i];
        cout << "Endereço: ";
        cin >> endereco[i];
        cout << "Email: ";
        cin >> email[i];
        cout << "Telefone: ";
        cin >> telefone[i];
        cout << "\n";
    }
    
    return 0;
}
