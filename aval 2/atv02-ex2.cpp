/*
* Crie um algoritmo que tenha um vetor explícito para armazenar 5 
* idades e um vetor não explícito para armazenar 5 nomes. Ao final Exiba o 
* nome da pessoa de maior idade, menor idade, a média das idades e o saldo 
* das idades. 
*/

#include "iostream"

using namespace std;

int idades[] = {18, 17, 19, 20, 25};
string nomes[5] = {};
int maior = 0, menor = 0, posMaior = 0, posMenor = 0;
int tamanhoNome = sizeof(nomes)/sizeof(string);
int tamanhoIdade = sizeof(idades)/sizeof(int);


string lerNome(){
    string nome;
    cout << "\nInsira um nome: " << endl;
    getline(cin, nome); 

    return nome;
}

void acharMaiorMenor(){

    for (int i = 0; i < tamanhoIdade; i++)
    {
        if (idades[i] > maior || i == 0) {
            maior = idades[i];
            posMaior = i;
        }

        if (idades[i] < menor || i == 0) {
            menor = idades[i];
            posMenor = i;
        }
    }
}

int acharSaldo(){
    int saldo = 0;
    for (int i = 0; i < tamanhoIdade; i++)
    {
        saldo += idades[i];
    }
    return saldo;
}
float acharMedia(){
    float media = 0;
    media = acharSaldo();
    media /= tamanhoIdade;

    return media;
}


void mostrar(){
    float media = 0;
    int saldo = 0;
    acharMaiorMenor();
    media = acharMedia();
    saldo = acharSaldo();

    cout << "\nPessoa com a maior idade: " << nomes[posMaior] << ", " << maior << endl;
    cout << "Pessoa com a menor idade: " << nomes[posMenor] << ", " << menor << endl;
    cout << "Media das idades: " << media << endl;
    cout << "Saldo das Idades: " << saldo << endl;

}

int main(int argc, char const *argv[])
{
    
    for (int i = 0; i < tamanhoNome; i++)
    {
        nomes[i] = lerNome();
    }
    
    mostrar();

    return 0;
}
