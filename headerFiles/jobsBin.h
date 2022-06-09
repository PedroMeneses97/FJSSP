

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



