
// Struct de Operações
typedef struct Operacoes {

	int idOperacao;
	char *descricao;
	struct Maquinas *maquinas;
	struct Operacoes *seguinte;

} Operacoes;



/**
 * Função para criar Operacoes
 * Recebe um id da operacao
 * Recebe uma descricao da operacao
 * Dentro da função vamos criar uma nova operacao utilizando malloc
*/
Operacoes* CriaOperacoes(int id, char *desc);


/**
 * Função que insere operacao na lista
 * Recebe como parametro o inicio da lista
 * Recebe como parametro a nova operacao
*/
Operacoes* InsereOperacao(Operacoes* inicio, Operacoes* nova);


/**
 * Função que altera o nome de uma operação
 * Recebe como parametro uma operacao
 * Recebe como parametro o id da operacao a alterar
 * Recebe como parametro o novo nome da operacao
*/
Operacoes* alterarOperacao(Operacoes* operacao, int idOperacao, char nomeNovo[]);


/**
 * Função que altera o tempo de uma Maquina a partir de um ID
 * Recebe como parametro o inicio da lista das Operações
 * Recebe um ID da operação na qual eu quero ir alterar uma maquina
 * Recebe uma lista de maquinas na qual vamos percorrer para alterar o tempo
 * Recebe o id da maquina a alterar
 * Recebe o novo tempo da maquina
*/
Operacoes *InsereMaquinasOperacao(Operacoes* inicio,int id, Maquinas *maquinas,int idMaquina,double tempo);


/**
 * Função que lista todas as operações da lista passado por parametro
*/
void ListaOperacoes(Operacoes *inicio);



bool VerificaOperacao(Operacoes *inicio, int cod);
