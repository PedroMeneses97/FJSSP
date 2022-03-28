#define _CRT_SECURE_NO_DEPRECATE

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"



int main() {


	// Variaveis

	Maquinas *inicio = NULL;  // Lista null
	Maquinas* nova;

	Operacoes* novaOp;
	Operacoes *inicioLista = NULL;

	Jobs* novoJob;
	Jobs *inicioJobs = NULL;



	/**
	* Criar Maquinas individualmente
	* Insere a Maquina no inicio da lista
	*/
	nova = CriaMaquina(1, "Maquina 1",4);
	inicio = InsereMaquinaInicio(inicio, nova);

	nova = CriaMaquina(2, "Maquina 2",4);
	inicio = InsereMaquinaInicio(inicio, nova);

	nova = CriaMaquina(3, "Maquina 3",6);
	inicio = InsereMaquinaInicio(inicio, nova);

	nova = CriaMaquina(4, "Maquina 4",8);
	inicio = InsereMaquinaInicio(inicio, nova);

	//Listar máquinas
	printf("\nListar Máquinas\n");
	ListarMaquinas(inicio);

	// Lista o ultimo elemento que foi inserido na Lista das Maquinas.
	listarUltimo(inicio);

	/*---------------------------------------------------------------------------------------------------------------*/

	printf("\n\nListar Operações\n");


	
	/* OPERAÇÕES */
	novaOp = CriaOperacoes(1, "Operacao 1",  inicio);
	inicioLista = InsereOperacao(inicioLista, novaOp);
	
	novaOp = CriaOperacoes(2, "Operação 2", inicio);
	inicioLista = InsereOperacao(inicioLista, novaOp);


	novaOp = CriaOperacoes(3, "Operação 3", inicio);
	inicioLista = InsereOperacao(inicioLista, novaOp);
	
	novaOp = CriaOperacoes(4, "Operação para apagar", inicio);
	inicioLista = InsereOperacao(inicioLista, novaOp);

	

	//Listar máquinas
	ListaOperacoes(inicioLista);


	//printf("\n---------------\n APAGAR");
	//removerOperacao(inicioLista, 4);
	//ListaOperacoes(inicioLista);
	//
	
	/*---------------------------------------------------------------------------------------------------------------*/

	printf("\n\nListar Jobs\n");
	
	novoJob = CriaJobs(1, "Job Um", inicioLista);
	inicioJobs = InsereJobs(inicioJobs, novoJob);

	novoJob = CriaJobs(2, "Job Dois", inicioLista);
	inicioJobs = InsereJobs(inicioJobs, novoJob);

	ListaJobs(inicioJobs);




	printf("\n  ################################## IMPRIMIR PARA O FICHEIRO ######################################## \n");
	/* ################################## IMPRIMIR PARA O FICHEIRO ########################################*/

	FILE *fptr;
	char chr;

	// Verica se o caminho do ficheiro é válido
	if ((fptr = fopen("D:\\teste.txt", "r")) == NULL) {
		printf("Error! opening file");

		// Se for nulo, sai automaticamente.
		exit(1);
	}
	else {
		// Definir que a partir deste momento vamos escrever no ficheiro
		fptr = fopen("D:\\teste.txt", "w");

		Maquinas *auxiliarFicheiro = inicio;
		while (auxiliarFicheiro != NULL) {
			fprintf(fptr, "%d - %s - %f\n", auxiliarFicheiro->cod,auxiliarFicheiro->nome,auxiliarFicheiro->tempo);
			auxiliarFicheiro = auxiliarFicheiro->proximoValor;
		}
	
		fclose(fptr);

	}


	/* LER FICHEIRO */

	if ((fptr = fopen("D:\\teste.txt", "r")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	else {
		fptr = fopen("D:\\teste.txt", "r");
		Maquinas *auxiliarFicheiro = inicio;
		chr = getc(fptr);
	
		while (chr != EOF)
		{
			printf("%c", chr);
			chr = fgetc(fptr);
		}
		
		
		fclose(fptr);

	}




	return (0);
}