// k) Elaborar um programa que efetue a apresentação do valor da conversão em dólar de um valor lido em real. O programa deve solicitar o valor da cotação do dólar e também a quantidade de reais disponível com o usuário, para que seja apresentado o valor em moeda americana.

#include <iostream>
using namespace std;

double converterEmDolar(double c, double r);

int main(int argc, char const *argv[])
{
    double cotacao = 0;
    double reais = 0;

    cout << "Insira a cotação do dolar: ";
    cin >> cotacao;
    cout << "Insira seu dinheiro: R$";
    cin >> reais;

    cout << "Seu dinheiro convertido em dolar: U$" << converterEmDolar(cotacao, reais) << endl;

    return 0;
}

double converterEmDolar(double c, double r){
    return r / c;
}