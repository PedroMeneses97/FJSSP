#define _CRT_SECURE_NO_DEPRECATE

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"



int main() {

	setlocale(LC_ALL, "Portuguese");

	// Variaveis
	Maquinas *listaMaquinas = NULL;   // Lista null
	Maquinas* nova;

	Operacoes* novaOp;
	Operacoes *listaOperacoes = NULL;

	Jobs* novoJob;
	Jobs *inicioJobs = NULL;



	/**
	* Criar Maquinas individualmente
	* Insere a Maquina no inicio da lista
	*/
	printf("\t\t\n\n ##################### Listar Maquinas ##################\n\n\n");

	nova = CriaMaquina(1, "Maquina XPTO 1", 1);
    listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

	nova = CriaMaquina(2, "Maquina XPTO 2", 2);
    listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

    nova = CriaMaquina(3, "Maquina XPTO 3", 3);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

    nova = CriaMaquina(4, "Maquina XPTO 4", 4);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

    nova = CriaMaquina(5, "Maquina XPTO 5", 5);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

    nova = CriaMaquina(6, "Maquina XPTO 6", 6);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);
    
    nova = CriaMaquina(7, "Maquina XPTO 7", 7);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

    nova = CriaMaquina(8, "Maquina XPTO 8", 8);
	listaMaquinas = InsereMaquinaInicio(listaMaquinas,nova);

	ListarMaquinas(listaMaquinas);

    // CalculaMinimoMaquina(inicio);
	//// Lista o ultimo elemento que foi inserido na Lista das Maquinas.
	//listarUltimo(inicio);

	/*---------------------------------------------------------------------------------------------------------------*/

	printf("\t\t\n\n ##################### Listar Operacoes ##################\n\n\n");

    novaOp = CriaOperacoes(1, "Operacao 1");
	listaOperacoes = InsereOperacao(listaOperacoes, novaOp);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,1,listaMaquinas,1,4);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,1,listaMaquinas,3,5);

    novaOp = CriaOperacoes(2, "Operacao 2");
	listaOperacoes = InsereOperacao(listaOperacoes, novaOp);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,2,listaMaquinas,2,4);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,2,listaMaquinas,4,5);

    novaOp = CriaOperacoes(3, "Operacao 3");
	listaOperacoes = InsereOperacao(listaOperacoes, novaOp);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,3,listaMaquinas,3,5);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,3,listaMaquinas,5,6);

    novaOp = CriaOperacoes(4, "Operacao 4");
	listaOperacoes = InsereOperacao(listaOperacoes, novaOp);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,4,listaMaquinas,4,5);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,4,listaMaquinas,5,5);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,4,listaMaquinas,6,4);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,4,listaMaquinas,7,5);
    listaOperacoes = InsereMaquinasOperacao(listaOperacoes,4,listaMaquinas,8,9);

    // Operação para ser Eliminada
    novaOp = CriaOperacoes(5, "Operacao 5");
	listaOperacoes = InsereOperacao(listaOperacoes, novaOp);
    alterarOperacao(listaOperacoes,5,"Operacao Nova"); // Altera nome da operação 5 para Operação nova

    ListaOperacoes(listaOperacoes);
   
    
    novoJob = CriaJobs(1,"Job 1");
    inicioJobs = InsereJobs(inicioJobs,novoJob);
    inicioJobs = InsereOperacaoJob(inicioJobs,1,listaOperacoes,1);
    inicioJobs = InsereOperacaoJob(inicioJobs,1,listaOperacoes,2);
    inicioJobs = InsereOperacaoJob(inicioJobs,1,listaOperacoes,3);
    inicioJobs = InsereOperacaoJob(inicioJobs,1,listaOperacoes,4);
    inicioJobs = InsereOperacaoJob(inicioJobs,1,listaOperacoes,5); // Irá ser Eliminada

    // ListaJobs(inicioJobs);

    DeleteOperacao(inicioJobs,5,1); // Apagar a operação 5.

    ListaJobs(inicioJobs);

    CalculaTempoMinimoOperacoesMaquinas(inicioJobs,1);
    CalculaTempoMaximoOperacoesMaquinas(inicioJobs,1);
    CalculaMediaOperacoesMaquinas(inicioJobs,1);

    // FICHEIROs

    EscreveFicheiro(inicioJobs);
    LerFicheiro();

	return (0);
}