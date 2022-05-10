#include "Lista.h"

int main(){

	Lista l;
    Item i;
    FILE *f;	
    FazListaVazia(&l);
    f = fopen("nomes.txt", "r");
    while (fgets(i.nome, 20, f) != NULL){
        if (i.nome[strlen(i.nome)-1] == '\n')
            i.nome[strlen(i.nome)-1] = '\0';
        InsereNaLista(&l, i);
    }
    printf("\nLista inserida: ");
    ImprimeLista(&l);
    fclose (f);

    removeNomeRepetido(&l);

	return 0;
}
