#define _CRT_SECURE_NO_DEPRECATE
#include "header.h"


JobsBin* CriaNodo (Jobs* job){
    JobsBin* novo = (JobsBin*)malloc(sizeof(JobsBin));
    novo->job = job;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função que recebe a arvore binária e o job a inserir
JobsBin* InsereJobBinario(JobsBin* inicio, Jobs* job){

    // Se a arvore estiver vazia
    if(inicio == NULL){
        inicio = CriaNodo(job);
    }

    else{
        // Se o job for menor que o job atual
        if(job->idJob < inicio->job->idJob){
            inicio->esquerda = InsereJobBinario(inicio->esquerda, job);
        }
        // Se o job for maior que o job atual
        else if(job->idJob > inicio->job->idJob){
            inicio->direita = InsereJobBinario(inicio->direita, job);
        }
    }
    return inicio;
}

void ListaJobBinario(JobsBin* inicio){

    if(inicio == NULL){
        printf("\n vazio \n");
    }
    else{
        printf("\n ( J: %d O: %d M:%d", inicio->job->idJob,inicio->job->operacoes->idOperacao,inicio->job->operacoes->maquinas->cod);
        ListaJobBinario(inicio->esquerda);
        ListaJobBinario(inicio->direita);
        printf(")");
    }

}

bool ExisteJobBin(JobsBin* inicio, int idJob){
    
    JobsBin *aux = inicio;
    
        while(aux != NULL){
    
            if(aux->job->idJob == idJob){
                return true;
            }
            else if(idJob < aux->job->idJob){
                aux = aux->esquerda;
            }
            else{
                aux = aux->direita;
            }
        }
        return false;
}

JobsBin* GetData(char* fileName) {
	FILE* fp;
	JobsBin* h = NULL;
    JobFile aux;
    Jobs *job = NULL;
	char linhaFicheiro[100];

	if ((fp = fopen(fileName, "r")) == NULL) return NULL;
	
	while (fgets(linhaFicheiro,100,fp) != NULL){

		// idJob;idOper;idMaq;Tempo 
		sscanf(linhaFicheiro,"%d;%d;%d;%f", &aux.j, &aux.o, &aux.m, &aux.t);

        if(ExisteJobBin(h, aux.j) == false){
            job = CriaJobs(aux.j, "");
            h = InsereJobBinario(h, job);
        }

        if(VerificaOperacao(job->operacoes, aux.o) == false){

            Operacoes* novaOp;
            novaOp = CriaOperacoes(aux.o, "");
            job->operacoes = InsereOperacao(job->operacoes, novaOp);
        }
        
        if(VerificaMaquina(job->operacoes->maquinas, aux.m) == false){
            Maquinas* novaMaq;
            novaMaq = CriaMaquina(aux.m, "",aux.t);
            job->operacoes->maquinas = InsereMaquinaInicio(job->operacoes->maquinas, novaMaq);
        }
	}
	
    fclose(fp);
	return h;
}

void EscreveFicheiroE(char* fileName, JobsBin* h) {
    FILE* fp;

    if ((fp = fopen(fileName, "w")) == NULL) return;

    EscreveFicheiroRec(fp, h);

    fclose(fp);
}

void EscreveFicheiroRec(FILE* fp, JobsBin* h) {
    if (h == NULL) return;
    fprintf(fp, "%d;%d;%d;%f\n", h->job->idJob, h->job->operacoes->idOperacao, h->job->operacoes->maquinas->cod, h->job->operacoes->maquinas->tempo);
    EscreveFicheiroRec(fp, h->esquerda);
    EscreveFicheiroRec(fp, h->direita);
}

JobsBin* GetTudoFicheiro(char* fileName) {

	FILE* fp;
    JobFile aux;

    JobsBin* headBin = NULL;
    JobsBin* novoNodo;

    Jobs* headJobs = NULL;
    Jobs* novoJob;

    Operacoes* headOperacoes = NULL;
    Operacoes* novaOperacao;

    Maquinas* headMaq = NULL;
    Maquinas* novaMaq;

	char linhaFicheiro[100];

	if ((fp = fopen(fileName, "r")) == NULL) return NULL;
	
	while (fgets(linhaFicheiro,100,fp) != NULL){

		// idJob;idOper;idMaq;Tempo 
		sscanf(linhaFicheiro,"%d;%d;%d;%f", &aux.j, &aux.o, &aux.m, &aux.t);

        if(ExisteJobBin(headBin, aux.j) == false){
            novoJob = CriaJobs(aux.j, "");
            headBin = InsereJobBinario(headBin, novoJob);
        }

        headOperacoes = headBin->job->operacoes;
        if(VerificaOperacao(headOperacoes, aux.o) == false){
            novaOperacao = CriaOperacoes(aux.o, "");
            headOperacoes = InsereOperacao(headOperacoes, novaOperacao);
        }
        
        headMaq = headBin->job->operacoes->maquinas;
        if(VerificaMaquina(headMaq, aux.m) == false){
            novaMaq = CriaMaquina(aux.m, "",aux.t);
            headMaq = InsereMaquinaInicio(headMaq, novaMaq);
        }
	}
	
    
    fclose(fp);
	return headBin;
}

void EscreveNovaInfoFicheiro(int idJob, int idOperacao, int idMaquina, float tempo){
 

    FILE* fp;
    char linhaFicheiro[150];
    Operacoes* auxOper = NULL;


    if ((fp = fopen("teste2.txt", "a")) == NULL) return;

    sprintf(linhaFicheiro,"%d;%d;%d;%f;\n", idJob, idOperacao, idMaquina, tempo);

    if(VerificaOperacao(auxOper,idOperacao) == false){
        fputs(linhaFicheiro,fp);
    }
    

    fclose(fp);
}

