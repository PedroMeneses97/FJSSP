
// Struct de Jobs
typedef struct Jobs {

	int idJob;
	char *nomeJob;
	struct Operacoes *operacoes;
	struct Jobs *seguinte,*anterior;

} Jobs;

typedef struct JobFile {
	int j;
	int o;
	int m;
	float t;
}JobFile;



/**
 * Função para criar Jobs
 * Recebe um ID e um Nome para instanciar um job
*/
Jobs* CriaJobs(int idJob, char *nome);


/**
 * Função que insere jobs na lista passada por parametro
 * Recebe um novo Job
*/
Jobs* InsereJobs(Jobs* inicio, Jobs* nova);


/**
 * Função que insere uma operações em um job
 * Recebe como parametro o inicio da lista de jobs
 * Recebe como parametro o id do job a qual vamos inserir as operações
 * Recebe como parametro a lista de operações 
 * Recebe como parametro o id da operação que vamos inserir
*/
Jobs *InsereOperacaoJob(Jobs* inicioListaJobs,int idJob, Operacoes *operacoes,int idOperacao);


/**
 * Função que remove uma operação de um job
 * Recebe como parametro o inicio da lista de jobs
 * Recebe como parametro o id da Operação a qual vamos remover
 * Indicamos por parametro qual é o id do Job a qual vamos remover a operação
*/
Jobs *DeleteOperacao(Jobs *listaDeJobs, int idOperacao, int idJob);


/**
 * Função que calcula o tempo minimo de cada operação de um job
 * Recebe a lista dos Jobs e o ID do job a qual vamos calcular o tempo minimo
 * Calcula o tempo minimo para cada operação e soma-os apresentando um tempo mínimo para cada Operação.
*/
void CalculaTempoMinimoOperacoesMaquinas(Jobs* inicio, int idJob);


/**
 * Função que calcula o tempo maximo de cada operação de um job
 * Recebe a lista dos Jobs e o ID do job a qual vamos calcular o tempo maximo
 * Calcula o tempo maximo para cada operação e soma-os apresentando um tempo maximo para cada Operação.
*/
void CalculaTempoMaximoOperacoesMaquinas(Jobs* inicio, int idJob);


/**
 * Função que calcula a media de cada operação de um job
 * Recebe a lista dos Jobs e o ID do job a qual vamos calcular a media
 * Calcula a soma dos tempos de cada maquina de uma X operação para cada depois somarmos tudo e dividir pelo numero de operações existentes
*/
void CalculaMediaOperacoesMaquinas(Jobs* inicio, int idJob);


/**
 * Função que calcula o tempo total de um job
 * Recebe a lista de Jobs que vamos listar
*/
void ListaJobs(Jobs *inicio);



// Function that deletes a Job
Jobs* ApagaJob(Jobs *inicio, int idJob);


bool VerificaJobs(Jobs *inicio, int cod);




/**
 * Função que escreve os jobs num ficheiro
 * Recebe a lista dos jobs para escrevermos num ficheiro.
*/
void EscreveFicheiro(Jobs* listaJobs);


/**
 * Função que vai ler o que estiver presente no ficheiro teste.txt
 * Caso ele não exista, irá retornar um erro na consola.
*/
void LerFicheiro();






// Create a struct of jobs that is a binary tree
typedef struct JobsBin {

	Jobs *job;
	struct JobsBin *esquerda;
	struct JobsBin *direita;
	
} JobsBin;




// Cria um nodo novo
JobsBin* CriaNodo (Jobs* job);

/**
 * @brief Função que cria uma lista de jobs binária
 * 
 * @param inicio 
 * @param job 
 * @return JobsBin* 
 */
JobsBin* InsereJobBinario(JobsBin* inicio, Jobs* job);

// Listar jobs em arvore binária com a função listaJobBinario do tipo JobsBin que recebe o inicio da arvore
// Lista de forma PreOrder
void ListaJobBinario(JobsBin* inicio);



JobsBin* GetData(char* fileName);



