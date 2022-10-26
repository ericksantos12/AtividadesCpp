#include "iostream"
#include "cstdlib"

using namespace std;
typedef struct me cad;

int cont = 0;

struct me {
    int pos;
    cad * liga; // struct me * liga
};

cad * ultimoNO;
cad * primeiroNO;


void alocar() {
    /*
    SEMPRE QUANDO ESSE METODO RODA ELE ALOCA UM ENDEREÇO DE MEMORIA NOVO NO NEWCAD.
    depois de todas as operações ele guarda ele no ultimoNO
    Newcad é literalmente um ponteiro temporario
    */
    cont++;
    cad * newcad = (cad * ) malloc(sizeof(cad)); // alocando memoria do tamanho do struct e apontado para ela com o newcad
    if (cont == 1) {
        newcad -> liga = NULL; // no do newcad é null pois é o primeiro cadastro
        newcad -> pos = cont; // pos do new cad se torna 1
        primeiroNO = newcad; // ponteiros do primeiro e ultimo no se torna o endereço do newcad
        ultimoNO = newcad;
    } else {
        ultimoNO -> liga = newcad; // ultimoNO recebe o endereço do new cad
        newcad -> liga = NULL; // liga do newcad se torna null
        newcad -> pos = cont; // newcad ganha a pos autal
    }
    ultimoNO = newcad; // ultimo aponta no newcad, ou seja, se torna ele.
}

void exibir() {
    cad * temp;
    temp = primeiroNO;
    while (temp != NULL) {
        cout << temp -> pos << endl;
        temp = temp -> liga;
    }
}

void destruir() {
    cad * temp;
    temp = primeiroNO;
    while (temp -> liga != NULL) {
        free(temp);
        temp = temp -> liga;
    }
    free(primeiroNO);
    free(ultimoNO);
}

int main() {
    for (int i = 0; i <= 4; i++)
        alocar();
    exibir();
    destruir();
}