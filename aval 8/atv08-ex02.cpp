/*
II - Projete uma estrutura chamada cad2 encadeada que contenha nódulos com os seguintes
atributos: int pos; string nome; *cad2 anterior; A estrutura deverá ser encadeada da seguinte
forma: Deverá ter um ponteiro chamado UltimoNo que para manter sempre o endereço de
memória do ultimoNo que será adicionado na estrutura. Cada nódulo deverá ter um ponteiro
interno do tipo *cad2 apontando para o nódulo/struct anterior até chegar no primeiro nódulo
adicionado que deverá ter seu ponteiro anterior apontando para NULL.
*/

// struct com int pos, string nome e cad2 * anterior
// ponteiro ultimono
// funcao alocar, exibir e destruir

#include "iostream"
#include "cstdlib"
using namespace std;

typedef struct me cad2;

struct me {
    int pos;
    string nome;
    cad2 * anterior;
};


int index = 0;
cad2 * ultimoNO;

/**
 * Sempre quando executado aloca um endereço de memória do tipo cad2 para um ponteiro temporário. Depois preenche esse struct e faz com que o ultimoNO aponte para o endereço de temp, assim descartando o ponteiro temporário. 
 * A partir do segundo endereço alocado, ele irá armazenar o endereço do ultimo nó no temporário, depois apontar o ultimo nó para o temporario, dessa forma o ultimo nó sempre terá armazenado seu endereço anterior.
 */
void alocar(string nome){
    cad2 * temp = (cad2 *) malloc(sizeof(cad2));

    temp->pos = ++index;
    temp->nome = nome;
    temp->anterior = index == 1 ? NULL : ultimoNO;

    ultimoNO = temp;
}

/**
 * Ponteiro temporario aponta para o último nó, e enquanto ele não for nulo ele mostra os valores do struct.
 * Após mostrar os valores, o ponteiro temporário aponta para o endereço anterior que está armazenado dentro dele mesmo
 */
void exibir(){
    cad2 * temp;
    temp = ultimoNO;
    while (temp != NULL)
    {
        cout << "Posicao: " << temp->pos << endl;
        cout << "Nome: " << temp->nome << endl;
        cout << "Endereco de Memoria: " << temp << endl << endl;

        temp = temp->anterior;
    }
}


void destruir(){
    cad2 * temp;
    cad2 * aux;

    temp = ultimoNO;

    while (temp != NULL)
    {
        aux = temp->anterior;
        cout << "Liberando " << temp << endl;
        free(temp);
        temp = aux;
    }
    ultimoNO = NULL;
    index = 0;
}


int main(int argc, char const *argv[])
{
    string nome;
    int key;

    MENU:

    system("cls");
    cout << "--|Alocacao Dinamica|-- \n1 -- Alocar Valores \n2 -- Exibir Valores \n3 -- Destruir Valores \n0 -- Sair" << "\n> ";
    cin >> key;
    system("cls");

    switch (key)
    {
    case 1:
        int n;

        cout << "Quantos cadastros deseja inserir? \n> ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "( " << i + 1 << " / " << n << " ) Digite um nome: ";
            cin >> nome;
            alocar(nome);
        }
        break;
    
    case 2:
        cout << "[!] Exibindo: " << endl << endl;
        exibir();
        break;
    
    case 3:
        cout << "[!] Destruindo..." << endl;
        destruir();
        break;
    
    case 0:
        cout << "[!] Liberando memoria..." << endl;
        destruir();

        cout << "[!] Encerrando programa" << endl;
        exit(0);
        break;
    
    default:
        break;
    }

    system("pause");
    goto MENU;
    return 0;
}
