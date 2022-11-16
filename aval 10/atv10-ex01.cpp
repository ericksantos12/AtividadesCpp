// * 1. Monte o programa FIFO colocando um menu de controle;
// * 2. Altere o código da FIFO, acrescente os atributos Nome e Cpf, faça as 
// * funções para buscar o nome de uma pessoa e também para excluir um 
// * registro através do nome, se você excluir um elemento da fila então deverá 
// * redirecionar os ponteiros para não quebrar o encadeamento da fila. 

#include <iostream>
#include <cstdlib>

using namespace std;
int total; // contar o total de elementos

struct noFifo {
    int chave; // Sequencial número
    // string nome;
    // string cpf;
    noFifo * prox; //ponteiro para guardar o próximo elemento da fifo
};

noFifo * primeiroNo; // endereço do primeiro elemento
noFifo * ultimoNo; // endereço do último elemento


void construtor() {
    primeiroNo = ultimoNo = NULL;
    total = 0;
    cout << "\nFIFO iniciada!\n";
}

bool vazia() {
    return (primeiroNo == NULL);
}

void inserirNo(int valor) {
    noFifo * novoNo = (noFifo * ) malloc(sizeof(noFifo));
    if (novoNo == NULL) {
        cout << "\nErro de alocação!" << endl;
        return;
    }
    // Configurar os atributos internos
    novoNo -> chave = valor; // coloca o valor
    // novoNo -> nome = nome;
    // novoNo -> cpf = cpf;
    novoNo -> prox = NULL; // configurar o ponteiro interno
    total++; // incrementa o total
    // configura atributos internos do novo Nó
    if (vazia() == true) {
        primeiroNo = novoNo;
        ultimoNo = novoNo;
    } else {
        ultimoNo -> prox = novoNo;
    }
    ultimoNo = novoNo;
}

void removerNo() {
    noFifo * temp; // ponteiro temporário
    temp = primeiroNo; // guarda o primeiro Nó que será removido
    if (!vazia()) {
        primeiroNo = temp -> prox;
    }
    free(temp);
    total--; // decrementa o total
}

void removerNome(int chave){
    noFifo * temp = primeiroNo;
    noFifo * anterior;

    while (temp != NULL)
    {
        if (temp->chave == chave)
        {
            anterior->prox = temp->prox;
            free(temp);
            break;
        } else
        {
            anterior = temp;
            temp = temp->prox;
        }
    }
}

void mostrar() {
    noFifo * temp;
    temp = primeiroNo;
    while (temp != NULL) {
        cout << temp -> chave << " ";
        temp = temp -> prox;
    }

    cout << endl;
    free(temp);
}

void destrutor() {
    noFifo * temp, * aux;
    temp = primeiroNo;
    while (temp != NULL) {
        aux = temp;
        temp = temp -> prox;
        free(aux);
    }
    cout << "\nFIFO destruida...!" << endl;
}

int main()
{
    construtor();
    int key;
    int valor;
    // string nome;
    // string cpf;

    MENU:

    system("cls");
    cout << "Escolha uma opcao" << endl
    << "1 -- Inserir" << endl
    << "2 -- Remover" << endl
    << "3 -- Remover por Nome" << endl
    << "4 -- Mostrar" << endl
    << "5 -- Destruir" << endl
    << "0 -- Fechar" << endl 
    << "> ";
    cin >> key;
    system("cls");

    switch (key)
    {
    case 1:
        cout << "Insira o valor da chave: ";
        cin >> valor;
        // cout << "Insira o nome: ";
        // cin >> nome;
        // cout << "Insira o CPF: ";
        // cin >> cpf;

        inserirNo(valor);
        break;
    
    case 2:
        cout << "Removendo primeiro valor da fila" << endl;
        removerNo();
        break;
    
    case 3:
        cout << "Insira o valor que deseja remover: ";
        cin >> valor;
        cout << "Removendo valor" << endl;
        removerNome(valor);
        break;
    
    case 4:
        cout << "Mostrando valores" << endl;
        mostrar();
        break;
    
    case 5:
        destrutor();
        break;
    
    case 0:
        destrutor();
        cout << "Encerrando programa" << endl;
        exit(0);
        break;
    
    default:
        break;
    }
    system("pause");
    goto MENU;
    return 0;
}
