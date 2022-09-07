// i) Ler dois inteiros (variáveis A e B) e imprimir o resultado do quadrado da diferença do primeiro valor pelo segundo.

#include <iostream>
#include <math.h>
using namespace std;

int calculo(int a, int b);

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;

    cout << "Insira o primeiro valor: ";
    cin >> a;

    cout << "Insira o segundo valor: ";
    cin >> b;

    cout << "O quadrado da diferenca entre o primeiro e o segundo valor e: " << calculo(a, b) << endl;

    return 0;
}

int calculo(int a, int b){
    return pow(a - b, 2);
}