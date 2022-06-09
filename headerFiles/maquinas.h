#include <stdbool.h>

// Estrutura de uma Máquina
typedef struct Maquinas {

	int cod;
	char *nome;
	double tempo;
	struct Maquinas *proximoValor;

} Maquinas;

/**
 * Função para criar Maquina
 * Recebe um codigo maquina 
 * Recebe um nome maquina
 * Recebe um tempo maquina
 * Dentro da função vamos criar uma nova maquina utilizando malloc 
*/
Maquinas* CriaMaquina(int cod, char *nome,double tempo);


/**
*	Função que insere maquina na lista
*	Recebe como parametro o inicio da lista
*	Recebe como parametro a nova maquina
*/
Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova);



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
void ListaUltimo(Maquinas *inicio);


bool VerificaMaquina(Maquinas *inicio, int cod);