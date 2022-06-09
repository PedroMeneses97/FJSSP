#define _CRT_SECURE_NO_DEPRECATE
#include "header.h"



int main() {

	setlocale(LC_ALL, "Portuguese");

	// Variaveis
	Maquinas *listaMaquinas = NULL;   // Lista null
	Maquinas* nova;

	Operacoes* novaOp;
	Operacoes *listaOperacoes = NULL;

	Jobs* novoJob;
    Jobs* listaApagada = NULL;
	Jobs *inicioJobs = NULL;
    Jobs* listaJobs = NULL;

    JobsBin *raizes = NULL;
    JobsBin *raizesMaq = NULL;

    //alterarOperacao(listaOperacoes,5,"Operacao Nova"); // Altera nome da operação 5 para Operação nova

    /* Listar Máquinas a partir de um ficheiro */
    listaMaquinas = GetDataMaquina("base.txt");
    // ListarMaquinas(listaMaquinas);

    /* Listar Operações a partir de um ficheiro */
    listaOperacoes = GetDataOperacoes("teste2.txt");
    //ListaOperacoes(listaOperacoes);
  

    /* Inserir mais dados no ficheiro antes de imprimir */
    // EscreveNovaInfoFicheiro(10,1,1,1.000);
    // EscreveNovaInfoFicheiro(10,2,1,1.000);
    EscreveNovaInfoFicheiro(11,3,1,1.000);

    /* Lista os Jobs a partir de um ficheiro */
    listaJobs = GetDataJobs();

    
    //EditaOperacaoJob(listaJobs, 11,3, "NOVA");
    //ListaOperacaoJobIndividual(listaJobs,11);

    //ListaNomesOperacoes(listaJobs);

    listaJobs = RemoveOperacaoJob(listaJobs,1,1);

    // listaJobs = ApagaJob(listaJobs,10);

    // Função que guarda o estado atual da lista após a remoção do Job
    //EscreveFicheiroJobs("teste2.txt",listaJobs);

    /* Função que Apaga um Job */
    //listaJobs = ApagaJob(listaJobs,1);



    //ListaJobs(listaJobs);


    /* Lista os Jobs da arvore binária*/
    raizes = GetData("base.txt");
    //raizes = GetTudoFicheiro("base.txt");

    /* Função que Calcula o Tempo Mínimo */
    //CalculaTempoMinimoOperacoesMaquinas(listaJobs,1);

    /* Função que Calcula o Tempo Máximo */
    // CalculaTempoMaximoOperacoesMaquinas(inicioJobs,1);

    /* Função que Calcula a Média */
    // CalculaMediaOperacoesMaquinas(inicioJobs,1);

    //ListaJobBinario(raizes);
  

	return (0);
}