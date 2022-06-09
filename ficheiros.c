#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"
#include <locale.h>

#define MAX 100

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

