/*
I - Faça um menu para testar o programa 4 e faça as alterações a seguir:
! B. Insira mais um atributo no struct para armazenar um número aleatório criado por uma função randomica
! C. Crie uma função que busque e exiba uma posição qualquer um dos nódulos da estrutura.
! D. Crie função que informe se a estrutura está vazia.
*/

#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;
typedef struct me cad;

int cont = 0;

struct me {
    int num;
    int pos;
    cad * liga;
};

cad * ultimoNO;
cad * primeiroNO;

bool vazia(){
    return primeiroNO == NULL ? true : false;    
}

int random(){
    return rand() % 100;
}

void alocar() {
    cont++;
    cad * temp = (cad * ) malloc(sizeof(cad)); 
    if (cont == 1) {
        temp -> num = random();
        temp -> liga = NULL;
        temp -> pos = cont;
        primeiroNO = temp;
    } else {
        temp -> num = random();
        temp -> liga = NULL;
        temp -> pos = cont;
        ultimoNO -> liga = temp;
    }
    ultimoNO = temp;
}

void exibir() {
    cad * temp;
    temp = primeiroNO;

    if (vazia() == true)
    {
        cout << "[!] A estrutura esta vazia!" << endl;
    } else
    {
        while (temp != NULL) {
            cout << "Numero: " << temp -> num << endl;
            cout << "Posicao: " << temp -> pos << endl << endl;
            temp = temp -> liga;
        }       
    }
}

void exibirPos() {
    cad * temp;
    temp = primeiroNO;
    int posicao;

    cout << "Escolha uma posicao: ";
    cin >> posicao;

    while (temp != NULL)
    {
        if (temp -> pos == posicao)
        {
            cout << endl << "Posicao escolhida:" << endl;
            cout << "Numero: " << temp->num << endl;
            cout << "Posicao: " << temp->pos << endl;
            cout << "Memory Address: " << temp->liga << endl << endl;

            break;
        }
        temp = temp -> liga;

    };
    
}

void destruir() {
    cad * temp;
    cad * aux;
    temp = primeiroNO;
    while (temp -> liga != NULL) {
        free(temp);
        temp = temp -> liga;
    }
    free(primeiroNO);
    free(ultimoNO);

    cont = 0;
    primeiroNO = NULL;
}



int main() {
    srand(time(NULL));

    int key = 0;

    MENU:
    system("cls");
    cout << "Escolha uma das opcoes: \n1 -- Alocar \n2 -- Exibir \n3 -- Exibir Posicao \n4 -- Destruir \n0 -- Sair \n> ";
    cin >> key;
    system("cls");

    switch (key)
    {
    case 1:
        cout << "[!] Alocando numero" << endl;
        alocar();
        break;
    case 2:
        cout << "[!] Exibindo posicoes" << endl;
        exibir();
        break;
    case 3:
        exibirPos();
        break;
    case 4:
        cout << "[!] Destruindo estruturas" << endl;
        destruir();
        break;
    case 0:
        cout << "[!] Encerrando programa" << endl;
        destruir();
        exit(0);
        break;
    
    default:
        break;
    }
    system("pause");
    goto MENU;

}