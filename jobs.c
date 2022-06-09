
#define _CRT_SECURE_NO_DEPRECATE
#include "header.h"

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
	else {
        bool valor = VerificaJobs(inicio,nova->idJob);

		if( valor == 1){
			printf("Jobs %d ja existe\n",nova->idJob);
			return inicio;
		}
        //insere sempre no inicio
		nova->seguinte = inicio;
		inicio = nova;
		return inicio;

	}

}

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

Jobs* RemoveOperacaoJob(Jobs* listaDeJobs, int idOperacao, int idJob){

    // Auxiliar lista de jobs
    Jobs* aux = listaDeJobs;

    // Percorre a lista enquanto ela for diferente de nulo
    while(aux != NULL){

        // Se o Job da lista for igual ao id do parametro
        if(aux->idJob == idJob){

            // Operações para auxiliar
            Operacoes* auxOp = aux->operacoes;
            Operacoes* auxOp2 = aux->operacoes;

            // Enquanto a lista de operações
            while(auxOp != NULL){


                // Se o id da operação vindo da lista for igual ao id da operação do parametro
                if(auxOp->idOperacao == idOperacao){

                    //  Se as listas forem identicas
                    if(auxOp == aux->operacoes){
                        aux->operacoes = auxOp->seguinte;

                        Maquinas* auxMaquinas = auxOp->maquinas;

                        while(auxMaquinas != NULL){
                            free(auxOp);
                            free(auxOp->maquinas);
                            return listaDeJobs;
                        }
                        
                    }

                    // Se não forem
                    else{
                        auxOp2->seguinte = auxOp->seguinte;
                        free(auxOp);
                        free(auxOp->maquinas);
                        return listaDeJobs;
                    }
                }
                            
                auxOp2 = auxOp;
                auxOp = auxOp->seguinte;
            }
        }
        aux = aux->seguinte;
    }
    return aux;
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
                // printf("\nTempo minimo: %d - maq: %s\n",tempoMinimo,nova->nome);

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

		printf("J: %d - %s\n", aux->idJob, aux->nomeJob);

		Operacoes *auxOp = aux->operacoes;
		// Enquanto houver operações para listar
		while (auxOp != NULL) {
			printf("\n\tO: %d - %s\n", auxOp->idOperacao, auxOp->descricao);
		

			Maquinas *auxMaq = auxOp->maquinas;
		
			// Enquanto houver maquinas para lista
			while (auxMaq != NULL) {
				printf("\t\tM: %d %s %f\n", auxMaq->cod, auxMaq->nome, auxMaq->tempo);
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

Jobs* ApagaJob(Jobs *inicio, int idJob) {

    Jobs *aux = inicio;
    Jobs *aux2 = inicio;

    // Enquanto o aux for diferente de null
    while (aux != NULL) {

        // Se o id do job for igual ao id do job que queremos apagar
        if (aux->idJob == idJob) {

            // Se o aux for igual ao inicio
            if (aux == inicio) {

                // Atribuimos o aux->seguinte ao inicio
                inicio = aux->seguinte;

                // Liberamos a memória do aux
                free(aux);

                // Retornamos o inicio
                return inicio;
            }

            // Caso contrário
            else {

                // Atribuimos o aux->seguinte ao aux2
                aux2->seguinte = aux->seguinte;

                // Liberamos a memória do aux
                free(aux);

                // Retornamos o inicio
                return inicio;
            }
        }

        // Caso contrário
        else {

            // Atribuimos o aux ao aux2
            aux2 = aux;

            // Atribuimos o aux->seguinte ao aux
            aux = aux->seguinte;
        }
    }

    // Retornamos o inicio
    return inicio;
}

bool VerificaJobs(Jobs *inicio, int cod){
    
    // Variável Auxiliar
    Jobs *aux = inicio;

    // Enquanto o aux for diferente de null
    while(aux != NULL){

        // Se o cod for igual ao cod do job que queremos verificar
        if(aux->idJob == cod){
            return true;
        }
        // Se o if não for true, passa para o seguinte até acabar a lista.
        aux = aux->seguinte;
    }
    return false;
}

void EscreveFicheiroJobs(char* fileName, Jobs* h) {
    FILE* fp;

    // Tenta abrir o ficheiro dado como parametro em modo de escrita.
    if ((fp = fopen(fileName, "w")) == NULL) return;

    // Incialização de uma variável auxiliar
    Jobs *aux = h;

    // Enquanto a lista não for nula irá percorrer.
    while (aux != NULL) {

        // Escreve o id do job e o nome
        fprintf(fp, "%d %s\n", aux->idJob, aux->nomeJob);

        // Inicialização de uma variável auxiliar
        Operacoes *auxOp = aux->operacoes;

        // Enquanto a lista de operações não for nula irá percorrer.
        while (auxOp != NULL) {

            // Escreve o id da operação e a descrição
            fprintf(fp, "\t%d %s\n", auxOp->idOperacao, auxOp->descricao);

            // Inicialização de uma variável auxiliar
            Maquinas *auxMaq = auxOp->maquinas;


            // Enquanto a lista de maquinas não for nula irá percorrer.
            while (auxMaq != NULL) {

                // Escreve o codigo da maquina, o nome da maquina e o tempo
                fprintf(fp, "\t\t%d %s %f\n", auxMaq->cod, auxMaq->nome, auxMaq->tempo);
                auxMaq = auxMaq->proximoValor;
            }

            // Atribui a auxOp ao seguinte da lista de operações
            auxOp = auxOp->seguinte;
        }

        // Se o seguinte for diferente de nulo, irá imprimir uma linha a separar job entre job
        if (aux->seguinte != NULL)
            fprintf(fp, "----------------------------------------------------------\n");

        // Passa para a próxima interação
        aux = aux->seguinte;
    }

    // Fechar o ficheiro
    fclose(fp);
}

Jobs* GetDataJobs() {

	FILE* fp;
    JobFile aux;

    Jobs* headJobs = NULL;
    Jobs* novoJob;

    Operacoes* headOperacoes = NULL;
    Operacoes* novaOperacao;

    Maquinas* headMaq = NULL;
    Maquinas* novaMaq;

	char linhaFicheiro[100];


	if ((fp = fopen("teste2.txt", "r")) == NULL){
        printf("Ficheiro inválido. A importar ficheiro original.");
        fp = fopen("base.txt", "r");
    }

	
	while (fgets(linhaFicheiro,100,fp) != NULL)
		{

		sscanf(linhaFicheiro,"%d;%d;%d;%f", &aux.j, &aux.o, &aux.m, &aux.t);

        
        if(VerificaJobs(headJobs,aux.j) == false){
            novoJob = CriaJobs(aux.j, "");
            headJobs = InsereJobs(headJobs, novoJob);
        }
        
        headOperacoes = headJobs->operacoes;

        if(VerificaOperacao(headOperacoes, aux.o) == false){
            novaOperacao = CriaOperacoes(aux.o, "");
            headOperacoes = InsereOperacao(headOperacoes, novaOperacao);
            headJobs = InsereOperacaoJob(headJobs, novoJob->idJob, novaOperacao, novaOperacao->idOperacao);


            headMaq = headJobs->operacoes->maquinas;
        }

         if(VerificaMaquina(headMaq, aux.m) == false){
            novaMaq = CriaMaquina(aux.m, "",aux.t);
            headMaq = InsereMaquinaInicio(headMaq, novaMaq);
            headOperacoes = InsereMaquinasOperacao(headJobs->operacoes, novaOperacao->idOperacao, headMaq, novaMaq->cod,novaMaq->tempo);
        }    


	}
	fclose(fp);
	return headJobs;
}

Jobs* ListaOperacaoJobIndividual(Jobs *inicio , int idjob){
    
    Jobs* aux = inicio;

    // Percorrer a lista de jobs
    while(aux != NULL){

        // Quando encontrar o id do Job na lista
        if(aux->idJob == idjob){
            Operacoes* auxOp = aux->operacoes;

            // Percorrer todas as operações
            while(auxOp != NULL){
                printf("O:%d %s\n", auxOp->idOperacao, auxOp->descricao);
                auxOp = auxOp->seguinte;
            }
        }
        
        aux = aux->seguinte;
    }

    return aux;
}

Jobs* EditaOperacaoJob(Jobs* listaDeJobs, int idJob, int idOperacao,char nomeNovo[]){

    // Auxiliar lista de jobs
    Jobs* aux = listaDeJobs;

    // Percorre a lista enquanto ela for diferente de nulo
    while(aux != NULL){

        // Se o Job da lista for igual ao id do parametro
        if(aux->idJob == idJob){

            // Operações para auxiliar
            Operacoes* auxOp = aux->operacoes;

            // Enquanto a lista de operações
            while(auxOp != NULL){

                // Se o id da operação vindo da lista for igual ao id da operação do parametro
                if(auxOp->idOperacao == idOperacao){
                    auxOp->descricao = nomeNovo;
                }       
                auxOp = auxOp->seguinte;
            }
        }

        aux = aux->seguinte;
    }
    
    return aux;
    
}