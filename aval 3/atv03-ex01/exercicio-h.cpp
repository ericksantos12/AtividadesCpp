/*
    h) Elaborar um programa que calcule e apresente o volume de uma caixa retangular, por meio da fórmula VOLUME <- COMPRIMEIRO * LARGURA * ALTURA
*/

#include <cstdlib>
#include <iostream>
using namespace std;

float volume = 0;
float comprimento = 0;
float largura = 0;
float altura = 0;

float calculoVolume(float c, float l, float a);

void pedirValores();

void mostrar();

int main(int argc, char const *argv[]) {
   
   pedirValores();
   
   mostrar();

   return 0;
}

void pedirValores(){
   cout << "Insira o comprimento do retângulo: ";
   cin >> comprimento;
   cout << "Insira a largura do retângulo: ";
   cin >> largura;
   cout << "Insira a altura do retângulo: ";
   cin >> altura;

}

float calculoVolume(float c, float l, float a){
    return c * l * a;
}

void mostrar(){
    volume = calculoVolume(comprimento, largura, altura);
    cout << "O volume do retângulo é: " << volume << endl;
}
