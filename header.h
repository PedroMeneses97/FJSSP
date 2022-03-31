#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// Estrutura de uma Máquina
typedef struct Maquinas {

	int cod;
	char *nome;
	double tempo;
	struct Maquinas *proximoValor;

} Maquinas;


// Struct de Operações
typedef struct Operacoes {

	int idOperacao;
	char *descricao;
	struct Maquinas *maquinas;
	struct Operacoes *seguinte;

} Operacoes;


// Struct de Jobs
typedef struct Jobs {

	int idJob;
	char *nomeJob;
	struct Operacoes *operacoes;
	struct Jobs *seguinte;

} Jobs;


/**
 * Função para criar Maquina
 * 
*/
Maquinas* CriaMaquina(int cod, char *nome,double tempo);


/**
*	Função que insere maquina na lista
*	recebe como parametro o inicio da lista e a nova maquina a ser inserida
*/
Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova);

Maquinas* InsereMaquinaFim(Maquinas* inicio, Maquinas* nova);



/**
Função que recebe como parametro o inicio da lista
Corre até que o valor dado como parametro for == NULL
*/
void ListarMaquinas(Maquinas *inicio);

/**
Função para listar o ultimo elemento da lista.
A função recebe o inicio da lista e percorre até que o inicio->proximoValor seja Null
Imprimindo a maquina no final.
*/
void listaUltimo(Maquinas *inicio);




/* ############################################################# CRIAÇÃO DE OPERAÇÕES ############################################################# */

Operacoes* CriaOperacoes(int id, char *desc);

Operacoes* InsereOperacao(Operacoes* inicio, Operacoes* nova);

Operacoes* alterarOperacao(Operacoes* operacao, int idOperacao, char nomeNovo[]);

Operacoes *InsereMaquinasOperacao(Operacoes* inicio,int id, Maquinas *maquinas,int idMaquina,double tempo);

void ListaOperacoes(Operacoes *inicio);


/* ############################################################# CRIAÇÃO DE JOBS ############################################################# */

Jobs* CriaJobs(int idJob, char *nome);

Jobs* InsereJobs(Jobs* inicio, Jobs* nova);

Jobs *InsereOperacaoJob(Jobs* inicioListaJobs,int idJob, Operacoes *operacoes,int idOperacao);

Jobs *DeleteOperacao(Jobs *listaDeJobs, int idOperacao, int idJob);

void CalculaTempoMinimoOperacoesMaquinas(Jobs* inicio, int idJob);

void CalculaTempoMaximoOperacoesMaquinas(Jobs* inicio, int idJob);

void CalculaMediaOperacoesMaquinas(Jobs* inicio, int idJob);

void ListaJobs(Jobs *inicio);












void EscreveFicheiro(Jobs* listaJobs);
void LerFicheiro();