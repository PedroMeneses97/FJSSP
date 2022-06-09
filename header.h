#define _CRT_SECURE_NO_DEPRECATE
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

// #include "./headerFiles/ficheiros.h"
// #include "./headerFiles/jobs.h"
// #include "./headerFiles/jobsBin.h"
// #include "./headerFiles/maquinas.h"
// #include "./headerFiles/operacoes.h"

/**
 * @brief Estrutura que representa uma Lista de Máquinas
 */
typedef struct Maquinas {

	int cod;
	char *nome;
	double tempo;
	struct Maquinas *proximoValor;

} Maquinas;


/**
 * @brief Estrutura que representa uma Lista de Operacoes
 */
typedef struct Operacoes {

	int idOperacao;
	char *descricao;
	struct Maquinas *maquinas;
	struct Operacoes *seguinte;

} Operacoes;


/**
 * @brief Função que cria uma nova lista de Jobs
 *
 */
typedef struct Jobs {

	int idJob;
	char *nomeJob;
	struct Operacoes *operacoes;
	struct Jobs *seguinte,*anterior;

} Jobs;


/**
 * @brief Estrutura Auxiliar para fazer fetch no ficheiro
 */ 
typedef struct JobFile {
	int j;
	int o;
	int m;
	float t;
}JobFile;


/**
 * @brief Estrutura que representa uma Lista de Jobs Binária
 */
typedef struct JobsBin {

	Jobs *job;
	struct JobsBin *esquerda;
	struct JobsBin *direita;
	
} JobsBin;



/**
 * @brief Função que cria uma nova Máquina
 * 
 * @param cod 
 * @param nome 
 * @param tempo 
 * @return Maquinas* 
 */
Maquinas* CriaMaquina(int cod, char *nome,double tempo);


/**
 * @brief Função que insere uma Máquina na lista Máquinas
 * 
 * @param inicio 
 * @param nova 
 * @return Maquinas* 
 */
Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova);


/**
 * @brief Função que Lista todas as máquinas
 * 
 * @param inicio 
 */
void ListarMaquinas(Maquinas *inicio);


/**
 * @brief Lista a ultima maquina da lista
 * 
 * @param inicio 
 */
void ListaUltimo(Maquinas *inicio);


/**
 * @brief Função que verifica se uma máquina já existe na lista
 * 
 * @param inicio 
 * @param cod 
 * @return true 
 * @return false 
 */
bool VerificaMaquina(Maquinas *inicio, int cod);



/**
 * @brief Função que cria uma nova Operacao
 * 
 * @param id 
 * @param desc 
 * @return Operacoes* 
 */
Operacoes* CriaOperacoes(int id, char *desc);



/**
 * @brief Função que insere uma Operacao na lista de Operacoes
 * 
 * @param inicio 
 * @param nova 
 * @return Operacoes* 
 */
Operacoes* InsereOperacao(Operacoes* inicio, Operacoes* nova);


/**
 * @brief Função que altera o nome de uma operação
 * 
 * @param operacao 
 * @param idOperacao 
 * @param nomeNovo 
 * @return Operacoes* 
 */
Operacoes* alterarOperacao(Operacoes* operacao, int idOperacao, char nomeNovo[]);



/**
 * @brief Função que insere uma Máquina numa Operação dada no parametro com o tempo da tabela do enunciado.
 * 
 * @param inicio 
 * @param id 
 * @param maquinas 
 * @param idMaquina 
 * @param tempo 
 * @return Operacoes* 
 */
Operacoes *InsereMaquinasOperacao(Operacoes* inicio,int id, Maquinas *maquinas,int idMaquina,double tempo);



/**
 * @brief Função que lista todas as operações da lista passado por parametro
 * 
 * @param inicio 
 */
void ListaOperacoes(Operacoes *inicio);


/**
 * @brief Função que verifica se uma operação já existe na lista de Operações
 * 
 * @param inicio 
 * @param cod 
 * @return true 
 * @return false 
 */
bool VerificaOperacao(Operacoes *inicio, int cod);



/**
 * @brief Função que cria um novo Job
 * 
 * @param idJob 
 * @param nome 
 * @return Jobs* 
 */
Jobs* CriaJobs(int idJob, char *nome);



/**
 * @brief Função que insere um Job na lista de Jobs
 * 
 * @param inicio 
 * @param nova 
 * @return Jobs* 
 */
Jobs* InsereJobs(Jobs* inicio, Jobs* nova);


/**
 * @brief Função que insere uma operação num job
 * 
 * @param inicioListaJobs 
 * @param idJob 
 * @param operacoes 
 * @param idOperacao 
 * @return Jobs* 
 */
Jobs *InsereOperacaoJob(Jobs* inicioListaJobs,int idJob, Operacoes *operacoes,int idOperacao);



/**
 * @brief Função que calcula o tempo minimo de cada operação de um job
 * 
 * @param inicio 
 * @param idJob 
 */
void CalculaTempoMinimoOperacoesMaquinas(Jobs* inicio, int idJob);



/**
 * @brief Função que calcula o tempo maximo de cada operação de um job
 * 
 * @param inicio 
 * @param idJob 
 */
void CalculaTempoMaximoOperacoesMaquinas(Jobs* inicio, int idJob);


/**
 * @brief Função que calcula a media de cada operação de um job
 * 
 * @param inicio 
 * @param idJob 
 */
void CalculaMediaOperacoesMaquinas(Jobs* inicio, int idJob);


/**
 * @brief Função que Lista uma lista de Jobs
 * 
 * @param inicio 
 */
void ListaJobs(Jobs *inicio);



/**
 * @brief Função que apaga um job passado por parametro numa designada lista de Jobs
 * 
 * @param inicio 
 * @param idJob 
 * @return Jobs* 
 */
Jobs* ApagaJob(Jobs *inicio, int idJob);


/**
 * @brief Função que verifica se um job já existe na lista de Jobs
 * 
 * @param inicio 
 * @param cod 
 * @return true 
 * @return false 
 */
bool VerificaJobs(Jobs *inicio, int cod);



/**
 * @brief Função que escreve para um ficheiro o conteúdo da lista de jobs
 * 
 * @param listaJobs 
 */
void EscreveFicheiro(Jobs* listaJobs);



/**
 * @brief Função que lê o conteúdo do ficheiro teste.txt
 */
void LerFicheiro();


/**
 * @brief Função que cria um novo Nodo de uma Árvore Binária
 * 
 * @param job 
 * @return JobsBin* 
 */
JobsBin* CriaNodo (Jobs* job);

/**
 * @brief Função que cria uma lista de jobs binária
 * 
 * @param inicio 
 * @param job 
 * @return JobsBin* 
 */
JobsBin* InsereJobBinario(JobsBin* inicio, Jobs* job);


/**
 * @brief Função que verifica se um job já existe na Árvore Binária
 * 
 * @param inicio 
 * @param idJob 
 * @return true 
 * @return false 
 */
bool ExisteJobBin(JobsBin* inicio, int idJob);


/**
 * @brief Função que lista a Arvore Binária em PreOrder
 * 
 * @param inicio 
 */
void ListaJobBinario(JobsBin* inicio);



/**
 * @brief Função que recebe um ficheiro como parametro que vai buscar todos os jobs,operações,maquinas e tempo de um process plan.
 * @brief Ele verifica se já existe um job/operacoes/maquinas na lista de jobs/operacoes/maquinas, se não existir ele cria um novo job/operacão/maquina e insere na lista de jobs/operacoes/maquinas.
 * 
 * @param fileName 
 * @return JobsBin* 
 */
JobsBin* GetData(char* fileName);


/**
 * @brief Função que vai buscar os dados de máquinas ao Ficheiro
 * 
 * @param fileName 
 * @return Maquinas* 
 */
Maquinas* GetDataMaquina(char* fileName);


/**
 * @brief Função que vai buscar os dados das Operações ao Ficheiro 
 * 
 * @param fileName 
 * @return Operacoes* 
 */
Operacoes* GetDataOperacoes(char* fileName);


/**
 * @brief Função que vai escrever no ficheiro de saída o conteúdo da lista de jobs
 * 
 * @param fileName 
 * @param h 
 */
void EscreveFicheiroE(char* fileName, JobsBin* h);


/**
 * @brief 
 * 
 * @param fp 
 * @param h 
 */
void EscreveFicheiroRec(FILE* fp, JobsBin* h);


/**
 * @brief Função que vai buscar ao ficheiro todos os dados do job
 * 
 * @return Jobs* 
 */
Jobs* GetDataJobs();



/**
 * @brief Função que vai buscar todas as informações de todos os process plans
 * 
 * @param fileName 
 * @return JobsBin* 
 */
JobsBin* GetTudoFicheiro(char* fileName);


/**
 * @brief Função que insere mais informação no ficheiro de saída secundário. Em que se der erro vai buscar o ficheiro original.
 * 
 * @param idJob 
 * @param idOperacao 
 * @param idMaquina 
 * @param tempo 
 */
void EscreveNovaInfoFicheiro( int idJob, int idOperacao, int idMaquina, float tempo);


// ##########################################################################################

/**
 * @brief Escreve no ficheiro a nova lista de Jobs
 * 
 * @param fileName 
 * @param h 
 */
void EscreveFicheiroJobs(char* fileName, Jobs* h);



/**
 * @brief Remoção de uma determinada operação de um job
 * 
 * @param listaDeJobs 
 * @param idOperacao 
 * @param idJob 
 * @return Jobs* 
 */
Jobs* RemoveOperacaoJob(Jobs* listaDeJobs, int idOperacao, int idJob);


/**
 * @brief Editar Operações Associadas a um Job.
 * 
 * @param listaDeJobs 
 * @param idJob 
 * @param idOperacao 
 * @return Jobs* 
 */
Jobs* EditaOperacaoJob(Jobs* listaDeJobs, int idJob, int idOperacao,char nomeNovo[]);

/**
 * @brief Lista toda a informação de uma lista de Operações.
 * 
 * @param inicio 
 * @param idJob
 */
Jobs* ListaOperacaoJobIndividual(Jobs *inicio , int idjob);


/**
 * @brief Função que faz free a uma lista de máquinas
 * 
 * @param listaDeMaquinas 
 * @return Maquinas* 
 */
Maquinas* LimparTodasMaquinas(Maquinas *listaDeMaquinas);