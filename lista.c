#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"
#include <locale.h>



Maquinas *CriaMaquina(int cod, char *nome,double tempo){

 //aloca espaço de memória
 Maquinas *nova = (Maquinas*)malloc(sizeof(Maquinas));

 nova->cod = cod;
 nova->nome =  nome;
 nova->tempo = tempo;
 nova->proximoValor = NULL;
 return nova;
}

Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova) {

	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else {		//insere sempre no inicio
		nova->proximoValor = inicio;
		inicio = nova;
		return inicio;

	}



}

Maquinas* CalculaMinimoMaquina(Maquinas *inicio){

    Maquinas* aux = inicio;

    if(aux == NULL) return 0;

    else{

        double minimo = 0;

        while (aux != NULL)
        {

            if(minimo > aux->tempo){
                minimo = aux->tempo;               
            }
            else{
                minimo = aux->tempo;               

            }
            
           aux = aux->proximoValor;
        }
        printf("Minimo: %f",minimo);
        return aux;
    }
}


void ListarMaquinas(Maquinas *inicio) {

	Maquinas *aux = inicio;

	while (aux != NULL) {
		
		printf("ID: %d : %s : %f\n", aux->cod,aux->nome,aux->tempo);
		aux = aux->proximoValor;
	}
}


/**
Função para listar o ultimo elemento da lista.
*/
void listarUltimo(Maquinas *inicio) {
	

	Maquinas *aux = inicio;

	while (aux != NULL) {

		aux = aux->proximoValor;
	}

	printf("O ultimo valor inserido na lista é: %d - %s - %f\n", inicio->cod, inicio->nome, inicio->tempo);

}





void EscreveFicheiro(Jobs* listaJobs) {


FILE *fptr;
char chr;

// Verica se o caminho do ficheiro é válido
if ((fptr = fopen("./teste.txt", "r")) == NULL) {
	printf("Error! opening file");

	// Se for nulo, sai automaticamente.
	exit(1);
}

else {
	// Definir que a partir deste momento vamos escrever no ficheiro
	fptr = fopen("./teste.txt", "w");



	Jobs *auxiliarFicheiro = listaJobs;

	while (auxiliarFicheiro != NULL) {
		fprintf(fptr, "%d - %s \n", auxiliarFicheiro->idJob, auxiliarFicheiro->nomeJob);

		Operacoes *auxOperacoes = auxiliarFicheiro->operacoes;
	
		while (auxOperacoes != NULL) {
			fprintf(fptr, "\n\t%d - %s \n", auxOperacoes->idOperacao, auxOperacoes->descricao);

			Maquinas *auxMaquinas = auxOperacoes->maquinas;
			while (auxMaquinas != NULL) {
				fprintf(fptr, "\n\t\t%d - %s - %.2f\n", auxMaquinas->cod, auxMaquinas->nome,auxMaquinas->tempo);
				auxMaquinas = auxMaquinas->proximoValor;
			}
			auxOperacoes = auxOperacoes->seguinte;

		}

		auxiliarFicheiro = auxiliarFicheiro->seguinte;

	}

	fclose(fptr);

}
}

void LerFicheiro() {

	FILE *fptr;
	char chr;

	if ((fptr = fopen("./teste.txt", "r")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	else {
		fptr = fopen("./teste.txt", "r");
		chr = getc(fptr);
	
		while (chr != EOF)
		{
			printf("%c", chr);
			chr = fgetc(fptr);
		}
		
		
		fclose(fptr);

	}

}