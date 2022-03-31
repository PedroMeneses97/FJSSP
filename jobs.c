
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"
#include <locale.h>

Jobs* CriaJobs(int idJob, char *nome) {

	//aloca espaço de memória
	Jobs *novoJob = (Jobs*)malloc(sizeof(Jobs));

	novoJob->idJob = idJob;
	novoJob->nomeJob = nome;
	novoJob->operacoes = NULL;
	novoJob->seguinte = NULL;

	return novoJob;

}


Jobs *InsereJobs(Jobs* inicio, Jobs* nova) {

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
 * Recebe inicio da lista de operações , o ID da operação a inserir valores, a maquina que vamos inserir fazendo a verificação pelo ID
*/
Jobs *InsereOperacaoJob(Jobs* inicioListaJobs,int idJob, Operacoes *operacoes,int idOperacao){

    Operacoes *novaOperacao = (Operacoes*)malloc(sizeof(Operacoes));
	Operacoes* auxOperacoes = operacoes;
	Operacoes* tempLista = NULL;
    Jobs* auxJobs = inicioListaJobs;
    int found = 0;

	// Enquanto o auxOperacoes for diferente de nulo irá correr até ao fim da lista
    while(auxOperacoes != NULL){

		// Se o id da operação for igual ao id do parametro
        if(auxOperacoes->idOperacao == idOperacao){
            
			// Found igual a 1
            found = 1;
            novaOperacao->idOperacao = auxOperacoes->idOperacao;
            novaOperacao->descricao = auxOperacoes->descricao;
			novaOperacao->maquinas = auxOperacoes->maquinas;
			
        }

        // Percorrer o while.
        auxOperacoes = auxOperacoes->seguinte;
    }


    // Se for encontrada uma Operação
    if(found != 0){

        // Percorrer a lista até ser o proxValor == NULL
        while (auxJobs != NULL)
        {
            // Se o ID Job for igual ao ID do parametro
            if(auxJobs->idJob == idJob){
                // ListaTemporaria é igual a JobsoPERACOES ( jobs -> op1 op2  etc etc)
                tempLista = auxJobs->operacoes;
                // Nova operacao por parametro , o seguinte valor é a listatemp
                novaOperacao->seguinte = tempLista;
                // A operacao do aux jobs é a nova operacao
                auxJobs->operacoes = novaOperacao;
			
            }

            auxJobs = auxJobs->seguinte;

        }
        return inicioListaJobs;
    }

    else{
        return inicioListaJobs;
    }

}

Jobs *DeleteOperacao(Jobs *listaDeJobs, int idOperacao, int idJob){

    Jobs *auxListaJobs = listaDeJobs;


    while (auxListaJobs != NULL)
    {
        Operacoes *nodoAtual = auxListaJobs->operacoes;
        Operacoes *nodoAnterior;

        if (nodoAtual->idOperacao == idOperacao)
        {
            auxListaJobs->operacoes = nodoAtual->seguinte;
            free(nodoAtual);
        }
        else
        {
            nodoAnterior = auxListaJobs->operacoes;// Armazena a informação da operação
            nodoAtual = nodoAnterior->seguinte; // Segue para a proxima operação
            while ((nodoAtual != NULL) && (nodoAtual->idOperacao != idOperacao))
            {
                nodoAnterior = nodoAtual;
                nodoAtual = nodoAtual->seguinte;
            }
            if (nodoAtual != NULL)
            {
                nodoAnterior->seguinte = nodoAtual->seguinte;
                free(nodoAtual);
            }
        }
        auxListaJobs = auxListaJobs->seguinte;
    }
    return auxListaJobs;
}

void CalculaTempoMinimoOperacoesMaquinas(Jobs* inicio, int idJob){

    Jobs *auxListaJobs = inicio;
    Operacoes *auxOperacoes;
    Maquinas *auxMaquinas;
    Maquinas *nova = (Maquinas*)malloc(sizeof(Maquinas)); // Maquina auxiliar para imprimir a maquina

    int tempoMinimo = 0;
    int resultado = 0;
    
    while (auxListaJobs != NULL)
    {
        if(auxListaJobs->idJob == idJob){

            auxOperacoes = auxListaJobs->operacoes;

            while(auxOperacoes != NULL){ // Percorrer a lista de operações

                tempoMinimo = 0; 
                nova = NULL; // Maquina inicializa-se a NULL
                auxMaquinas = auxOperacoes->maquinas;
                
                while(auxMaquinas != NULL){

                    nova = auxMaquinas;


                    if(auxMaquinas->tempo < tempoMinimo){
                        nova->nome = auxMaquinas->nome; // Guardamos o nome da maquina
                        tempoMinimo = auxMaquinas->tempo; // Guardamos o tempo da maquina
                    }
                    else if(tempoMinimo == 0){
                        nova->nome = auxMaquinas->nome; // Guardamos o nome da maquina
                        tempoMinimo = auxMaquinas->tempo; // Guardamos o tempo da maquina
                    }

                    auxMaquinas = auxMaquinas->proximoValor;
                }
                auxOperacoes = auxOperacoes->seguinte;
                
                resultado += tempoMinimo;
                printf("\nTempo minimo: %d - maq: %s\n",tempoMinimo,nova->nome);

            }
        }
        auxListaJobs = auxListaJobs->seguinte;
    }

    printf("\nResultado mínimo: %d\n",resultado);
}

void CalculaTempoMaximoOperacoesMaquinas(Jobs* inicio, int idJob){

    Jobs *auxListaJobs = inicio;
    Operacoes *auxOperacoes;
    Maquinas *auxMaquinas;
    Maquinas *nova = (Maquinas*)malloc(sizeof(Maquinas)); // Maquina auxiliar para imprimir a maquina

    int tempoMaximo = 0;
    int resultado = 0;
    
    while (auxListaJobs != NULL)
    {
        if(auxListaJobs->idJob == idJob){

            auxOperacoes = auxListaJobs->operacoes;

            while(auxOperacoes != NULL){ // Percorrer a lista de operações

                tempoMaximo = 0; 
                nova = NULL; // Maquina inicializa-se a NULL
                auxMaquinas = auxOperacoes->maquinas;
                
                while(auxMaquinas != NULL){

                    nova = auxMaquinas;

                    if(auxMaquinas->tempo > tempoMaximo){
                        nova->nome = auxMaquinas->nome;
                        tempoMaximo = auxMaquinas->tempo;
                    }
                     else if(tempoMaximo == 0){
                        nova->nome = auxMaquinas->nome;
                        tempoMaximo = auxMaquinas->tempo;
                    }
                  

                    auxMaquinas = auxMaquinas->proximoValor;
                }
                auxOperacoes = auxOperacoes->seguinte;
                
                resultado += tempoMaximo;
                printf("\nTempo maximo: %d - maq: %s\n",tempoMaximo,nova->nome);

            }
        }
        auxListaJobs = auxListaJobs->seguinte;
    }

    printf("\nResultado maximo: %d\n",resultado);

}

void CalculaMediaOperacoesMaquinas(Jobs* inicio, int idJob){
    
        Jobs *auxListaJobs = inicio;
        Operacoes *auxOperacoes;
        Maquinas *auxMaquinas;
        int contador =0;
        int media = 0;
        int resultado = 0;
        
        while (auxListaJobs != NULL)
        {
            if(auxListaJobs->idJob == idJob){
    
                auxOperacoes = auxListaJobs->operacoes;
    
                while(auxOperacoes != NULL){ // Percorrer a lista de operações
    
                    media = 0; 
                    auxMaquinas = auxOperacoes->maquinas;
                    
                    while(auxMaquinas != NULL){
    
                        media += auxMaquinas->tempo;
                        auxMaquinas = auxMaquinas->proximoValor;
                    }
                    auxOperacoes = auxOperacoes->seguinte;
                    contador++;
                    resultado += media;
                    printf("\nMedia: %d\n",media);
    
                }
            }
            auxListaJobs = auxListaJobs->seguinte;
        }
        
        resultado = resultado/contador;
        printf("\nResultado media: %d\n",resultado);
    
}

void ListaJobs(Jobs *inicio) {


	Jobs *aux = inicio;


	// Enquanto o aux for difernte de null
	while (aux != NULL) {

		printf("ID: %d - %s\n", aux->idJob, aux->nomeJob);

		Operacoes *auxOp = aux->operacoes;
		// Enquanto houver operações para listar
		while (auxOp != NULL) {
			printf("\n\top: %d - %s\n", auxOp->idOperacao, auxOp->descricao);
		

			Maquinas *auxMaq = auxOp->maquinas;
		
			// Enquanto houver maquinas para lista
			while (auxMaq != NULL) {
				printf("\t\tmaq: %d %s %f\n", auxMaq->cod, auxMaq->nome, auxMaq->tempo);
				auxMaq = auxMaq->proximoValor;

			}

			auxOp = auxOp->seguinte;
		}

		// Imprime uma linha de separação entre a cronologia dos jobs.
		if (aux->seguinte != NULL)
		{
			printf("----------------------------------------------------------\n");
		}

		aux = aux->seguinte;
	}
}
