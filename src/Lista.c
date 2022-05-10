#include "Lista.h"

void Troca(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void FazListaVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void InsereNaLista(Lista *l, Item d){
	if (l->last >= MAXTAM){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void RemoveDaLista(Lista *l, Item d){
	bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].nome == d.nome){
				Troca(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}

void ImprimeLista(Lista *l){
	for(int i=l->first; i<l->last; i++)
		printf("\n%s", l->vet[i].nome);
	printf("\n");
}


void removeNomeRepetido(Lista *l){
	for(int i=l->first; i<l->last-1; i++){
		if (l->vet[i].repetido != true){
			int contRepetido = 0;
			for (int j = i+1; j < l->last; j++){
				if (strcmp(l->vet[j].nome, l->vet[i].nome) == 0){
					contRepetido++;
					l->vet[j].repetido = true;
				}
			}
			if (contRepetido > 0){
				printf("\n%s repetiu %d vezes.\n", l->vet[i].nome, contRepetido);
			}
		}
	}
}