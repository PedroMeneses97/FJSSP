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


/**
*	Função que insere maquina na lista
*	recebe como parametro o inicio da lista e a nova maquina a ser inserida
*/
Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova) {

	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else{		//insere sempre no inicio
		nova->proximoValor = inicio;
		inicio = nova;
		return inicio;

	}



}


/**
Função que recebe como parametro o inicio da lista
Corre até que o valor dado como parametro for == NULL
*/
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





/* CRIAÇÃO DE OPERAÇÕES */
//Operacoes *CriaOperacoes(int id, char *desc, double tempo) {
//
//	//aloca espaço de memória
//	Operacoes *novaOperacao = (Operacoes*)malloc(sizeof(Operacoes));
//
//	novaOperacao->idOperacao = id;
//	novaOperacao->descricao = desc;
//	novaOperacao->tempo = tempo;
//	novaOperacao->seguinte = NULL;
//	return novaOperacao;
//
//}

Operacoes *CriaOperacoes(int id, char *desc, Maquinas *maquinas) {

	//aloca espaço de memória
	Operacoes *novaOperacao = (Operacoes*)malloc(sizeof(Operacoes));

	novaOperacao->idOperacao = id;
	novaOperacao->descricao = desc;
	novaOperacao->maquinas = maquinas;
	novaOperacao->seguinte = NULL;
	return novaOperacao;

}

Operacoes *InsereOperacao(Operacoes* inicio, Operacoes* nova) {
	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else {		//insere sempre no inicio
		nova->seguinte = inicio;
		inicio = nova;
		return inicio;

	}
}

/**
Função que recebe como parametro o inicio da lista
Corre até que o valor dado como parametro for == NULL
*/

void ListaOperacoes(Operacoes *inicio) {

	Operacoes *aux = inicio;



	while (aux != NULL) {
	
		printf("ID: %d - %s \n", aux->idOperacao, aux->descricao );

		while (aux->maquinas != NULL) {
			printf("Nome: %s \n", aux->maquinas->nome);
			aux->maquinas = aux->maquinas->proximoValor;
		}

		aux = aux->seguinte;
	}
}




/* ############################################################# JOBS ############################################################# */


Jobs *CriaJobs(int idJob, char *nome, Operacoes *operacoes) {

	//aloca espaço de memória
	Jobs *novoJob = (Jobs*)malloc(sizeof(Jobs));

	novoJob->idJob = idJob;
	novoJob->nomeJob = nome;
	novoJob->operacoes = operacoes;
	novoJob->seguinte = NULL;
	return novoJob;

}


Jobs *InsereJobs(Jobs* inicio, Operacoes* nova) {

	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else {		//insere sempre no inicio
		nova->seguinte = inicio;
		inicio = nova;
		return inicio;

	}

}


void ListaJobs(Jobs *inicio) {


	Jobs *aux = inicio;


	// Enquanto o aux for difernte de null
	while (aux != NULL) {

		printf("ID: %d - %s\n", aux->idJob, aux->nomeJob);

		// Enquanto houver operações para listar
		while (aux->operacoes != NULL) {
			printf("\top: %d - %s\n", aux->operacoes->idOperacao, aux->operacoes->descricao);
		
			// Enquanto houver maquinas para listar
			while (aux->operacoes->maquinas != NULL) {
				printf("maq: %d %s %f", aux->operacoes->maquinas->cod, aux->operacoes->maquinas->nome, aux->operacoes->maquinas->tempo);
				aux->operacoes->maquinas = aux->operacoes->maquinas->proximoValor;

			}

		
			aux->operacoes = aux->operacoes->seguinte;
		}

		// Imprime uma linha de separação entre a cronologia dos jobs.
		if (aux->seguinte != NULL)
		{
			printf("----------------------------------------------------------\n");
		}

		aux = aux->seguinte;
	}
}



//
//
//Operacoes *removerOperacao(Operacoes *inicio, int id) {
//
//
//		Operacoes* aux = inicio;
//		Operacoes* previo = aux;
//
//
//		while (aux && aux->idOperacao != id) {	//procura para revover
//			previo = aux;
//			aux = aux->seguinte;
//		}
//		if (aux != NULL) {					//se encontrou, remove
//			previo->seguinte = aux->seguinte;
//			free(aux);
//		}
//		
//		
//	
//	return inicio;
//	printf("\nfteste\n\n");
//}
//
