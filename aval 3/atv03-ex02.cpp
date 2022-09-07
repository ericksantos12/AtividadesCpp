/*
 Fazer o quadro resumo de subrotinas e código fonte de programa para ler 
 o comprimento e calcular o diâmetro, calcular o raio e finalmente a área de 
 um círculo; (Faça um menu com as opções necessárias. Utilize a 
 simulação 3 como referência/Modelo para fazer este trabalho. )
*/
// C = 2pi.r
// D = 2r
// A = pi * r²
// r = c/(2pi)

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

double const pi = 3.14159265359;

double calcularDiametro(double c);
double calcularRaio(double c);
double calcularArea(double c);
double lerComprimento();
int mostrarMenu();


int main(int argc, char const *argv[])
{
    int opcao = 0;

    MENU:

    system("CLS");
    opcao = mostrarMenu();

    switch (opcao)
    {
    case 1:
        cout << "O raio do circulo em metros sera: " << calcularRaio(lerComprimento()) << endl;
        system("pause");
        break;
    
    case 2:
        cout << "O diametro do circulo em metros sera: " << calcularDiametro(lerComprimento()) << endl;
        system("pause");
        break;

    case 3:
        cout << "A area do circulo em metros sera: " << calcularArea(lerComprimento()) << endl;
        system("pause");
        break;

    case 0:
        cout << "O programa foi encerrado!" << endl;
        exit(0);
        break;
    
    default:
        break;
    }

    goto MENU;
    
    return 0;
}

double calcularRaio(double c){
    return c / (2*pi);
}
double calcularDiametro(double c){
    return calcularRaio(c) * 2;
}
double calcularArea(double c){
    return pi * pow(calcularRaio(c), 2);
}
int mostrarMenu(){
    int ler = 0;
    cout << "Escolha uma das opcoes:\n1. Calcular o Raio\n2. Calcular o Diametro\n3. Calcular Area\n0. Sair do programa\n> ";
    cin >> ler;
    return ler;
}
double lerComprimento(){
    double ler = 0;
    cout << "Insira o comprimento do circulo: ";
    cin >> ler;
    return ler;
}