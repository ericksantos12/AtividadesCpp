#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    struct pessoa
    {
        string nome;
        int idade;
        char sexo;
    } p1;
    
    p1.nome = "Anderson";
    p1.idade = 20;
    p1.sexo = 'M';

    struct pessoa *px1;
    px1 = &p1;

    cout << px1 -> nome << endl; //output: Anderson

    return 0;
}
