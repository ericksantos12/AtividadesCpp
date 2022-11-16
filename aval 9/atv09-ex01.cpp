/*
* 1. [] Monte e execute o programa LIFO. Crie uma subrotina controle() contendo um menu para executar o código. 
* 2. [] Faça alterações no programa LIFO, crie o atributo nome dentro do struct, crie uma 
* função para buscar um valor na LIFO, quando o valor for encontrado você deverá 
* exibir o nome que está na mesma posição do valor encontrado, você pode criar o 
* atributo posição dentro do struct para ajudar.
*/
#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct nopilha pilha;

struct nopilha {
    int pos;
    int valor;
    // string nome;
    pilha * ant;
};

int cont; // para contar os nós
pilha * topo;

void construtor() {
    topo = NULL;
    cont = 0;
}

bool push(int valor) {
    pilha * newpilha = (pilha * ) malloc(sizeof(pilha));

    if (newpilha == NULL) return false;

    newpilha -> pos = ++cont;
    newpilha -> valor = valor;
    // newpilha -> nome = nome;
    newpilha -> ant = topo;
    topo = newpilha;
    return true;
}

bool pop() {
    int valor;
    pilha * temp;
    temp = topo;
    valor = topo -> valor;
    topo = topo -> ant;
    free(temp);
    cout << "\nO valor removido foi: " << valor << endl;
    return true;
}

void exibirpilha() {
    pilha * temp;
    temp = topo;

    while (temp != NULL) {
        cout << temp -> valor << endl;
        temp = temp -> ant;
    }
}

bool vazia() {
    return (topo == NULL);
}

void destrutor() {
    pilha * temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo -> ant;
        free(temp);
    }
    free(topo);
    cout << "\nPilha destruida com sucesso!\n";
}

int total() {
    pilha * temp;
    temp = topo;
    int cont = 0;
    while (temp != NULL) {
        cont++;
        temp = temp -> ant;
    }
    return cont;
}

void acharValor(int pos){
    pilha * temp;
    temp = topo;

    while (temp != NULL)
    {
        if (temp->pos == pos)
        {
            cout << "[!] Valor Encontrado:" << endl;
            cout << "Valor: " << temp->valor << endl;
        }
        temp = temp->ant;
    }
}


void controle(){
    int key;
    int valor;
    int pos;
    string nome;

    construtor();

    MENU:
    system("cls");
    cout << "Escolha uma das opcoes:" << endl
    << "1 -- Inserir" << endl
    << "2 -- Tirar" << endl
    << "3 -- Exibir" << endl
    << "4 -- Destruir" << endl
    << "5 -- Mostrar Total" << endl
    << "6 -- Encontrar Valor" << endl
    << "0 -- Fechar" << endl
    << "> ";
    cin >> key;
    system("cls");


    switch (key)
    {
    case 1:
        cout << "[?] Escolha um valor: ";
        cin >> valor;

        push(valor);
        
        cout << "[!] Valor " << valor << " inserido no topo da pilha" << endl;
        break;
    case 2:
        cout << "[!] Removendo valor do topo da pilha" << endl;
        pop();

        break;
    case 3:
        cout << "[!] Exibindo pilha" << endl;
        exibirpilha();
        break;
    case 4:
        cout << "[!] Destruindo pilha" << endl;
        destrutor();
        construtor();
        break;
    case 5:
        cout << "[!] Exibindo total da pilha" << endl;
        cout << "Total de elementos: " << total() << endl;
        break;

    case 6:
        cout << "[?] Digite a posicao que deseja encontrar: ";
        cin >> pos;
        acharValor(pos);
        break;
    case 0:
        cout << "[!] Encerrando programa..." << endl;

        destrutor();
        exit(0);
        break;
    
    default:
        break;
    }
    system("pause");
    goto MENU;

}

int main(int argc, char const *argv[])
{
    controle();
    return 0;
}
