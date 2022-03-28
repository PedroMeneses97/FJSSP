
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



Maquinas *CriaMaquina(int cod, char *nome,double tempo);
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




/**
Função que recebe como parametro  uma maquina
Corre a função a procurar o id da maquina que irá ser introduzida
*/
Maquinas* ProcuraMaquina(Maquinas* maquina, int cod);


Maquinas* TempoMaquina(Maquinas* maquina);

/* ############################################################# CRIAÇÃO DE OPERAÇÕES ############################################################# */

Operacoes *CriaOperacoes(int id, char *desc,Maquinas *maquinas);
Operacoes *InsereOperacao(Operacoes* inicio, Operacoes* nova);
void ListaOperacoes(Operacoes *inicio);


/* ############################################################# CRIAÇÃO DE JOBS ############################################################# */

Jobs *CriaJobs(int idJob, char *nome, Operacoes *operacoes);
Jobs *InsereJobs(Jobs* inicio, Operacoes* nova);
void ListaJobs(Jobs *inicio);









/* apagar */
Operacoes *removerOperacao(Operacoes *inicio, int id);