
#define _CRT_SECURE_NO_DEPRECATE
#include "header.h"


Operacoes *CriaOperacoes(int id, char *desc) {


	//aloca espaço de memória
	Operacoes *novaOperacao = (Operacoes*)malloc(sizeof(Operacoes));

	novaOperacao->idOperacao = id;
	novaOperacao->descricao = desc;
	novaOperacao->maquinas = NULL;
	novaOperacao->seguinte = NULL;
	return novaOperacao;

}

Operacoes *InsereOperacao(Operacoes* inicio, Operacoes* nova) {
	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else {		//insere sempre no inicio

        bool valor = VerificaOperacao(inicio,nova->idOperacao);

		if( valor == 1){
			printf("Operação %d ja existe\n",nova->idOperacao);
			return inicio;
		}
        else{
            nova->seguinte = inicio;
		    inicio = nova;
		    return inicio;
        }
		

	}
}

Operacoes *InsereMaquinasOperacao(Operacoes* inicioListaOperacoes,int idOperacao, Maquinas *maquinas,int idMaquina,double tempo){

    Maquinas *novaMaquina = (Maquinas*)malloc(sizeof(Maquinas));
    Operacoes* auxOperacoes = inicioListaOperacoes;
    Maquinas* auxMaquinas = maquinas;
    int found = 0;
    Maquinas* tempLista = NULL;


    // Percorrer as maquinas até o prox valor ser nulo. OU percorrer as maquinas enquanto for diferente de null
    while(auxMaquinas != NULL){

        // Se a maquina.codigo for igual ao ID passado por parametro
        if(auxMaquinas->cod == idMaquina){
            
            found = 1;
            // A nova máquina é igual a maquina por parametro.
            novaMaquina->cod = auxMaquinas->cod;
            novaMaquina->nome = auxMaquinas->nome;
            novaMaquina->tempo = tempo;
        }

        // Percorrer o while.
        auxMaquinas = auxMaquinas->proximoValor;
    }


    // Se for encontrada uma maquina
    if(found != 0){

        // Percorrer a lista até ser o proxValor == NULL
        while (auxOperacoes != NULL)
        {
            // Se o ID operação for igual ao ID do parametro
            if(auxOperacoes->idOperacao == idOperacao){

                // ListaTemporaria é igual a operacoesMaquinas ( operacoes -> maquina1 etc etc)
                tempLista = auxOperacoes->maquinas;
                // Nova maquina por parametro , o seguinte valor é a listatemp
                novaMaquina->proximoValor = tempLista;
                // A maquina do aux operações é a nova maquina
                auxOperacoes->maquinas = novaMaquina;
            }

            auxOperacoes = auxOperacoes->seguinte;

        }
        return inicioListaOperacoes;
    }

    else{
        return inicioListaOperacoes;
    }

}

Operacoes* alterarOperacao(Operacoes* operacao, int idOperacao, char nomeNovo[]) {
    Operacoes* auxInicioLista = operacao;
    Operacoes* nodoAnterior;


    /**
     * Corre a lista enquanto o inicio da lista(head) for diferente de NULL e o id da operação for diferente do id passado por parametro
     * Se o inicio da lista for difernte de nulo após correr o ciclo while , atribuir um novo nome passado por parametro
     * return do head.
    */
    while (auxInicioLista != NULL && auxInicioLista->idOperacao != idOperacao) 
    {
        nodoAnterior = auxInicioLista;                  /**< isto é importante...*/
        auxInicioLista = auxInicioLista->seguinte;
    }

    if (auxInicioLista != NULL)
    {
        auxInicioLista->descricao = nomeNovo;
    }

    return(operacao);
}

void ListaOperacoes(Operacoes *inicio) {

	Operacoes *aux = inicio;

	while (aux != NULL) {
	
		printf("O: %d - %s \n", aux->idOperacao, aux->descricao );

        Maquinas *auxMaq = aux->maquinas;

		while (auxMaq != NULL) {
			printf("   M: %d Tempo: %f\n", auxMaq->cod,auxMaq->tempo);
			auxMaq = auxMaq->proximoValor;
		}

		aux = aux->seguinte;
	}
}

bool VerificaOperacao(Operacoes *inicio, int cod){

	Operacoes *aux = inicio;

	while (aux != NULL) {

		if (aux->idOperacao == cod) {
			return true;
		}
		aux = aux->seguinte;
	}
	return false;
}


Operacoes* GetDataOperacoes(char* fileName) {
	FILE* fp;
	Operacoes* h = NULL;
    JobFile aux;
    Operacoes* novaOperacao;

    Maquinas* headMaq = NULL;
    Maquinas* novaMaq;


	char linhaFicheiro[100];

	if ((fp = fopen(fileName, "r")) == NULL) return NULL;
	
	while (fgets(linhaFicheiro,100,fp) != NULL)
		{

		// idJob;idOper;idMaq;Tempo 
		sscanf(linhaFicheiro,"%d;%d;%d;%f", &aux.j, &aux.o, &aux.m, &aux.t);

        if(VerificaOperacao(h, aux.o) == false){
            novaOperacao = CriaOperacoes(aux.o, "");
            h = InsereOperacao(h, novaOperacao);
        }

        headMaq = h->maquinas;

        if(VerificaMaquina(headMaq, aux.m) == false){
            novaMaq = CriaMaquina(aux.m, "",aux.t);
            headMaq = InsereMaquinaInicio(headMaq, novaMaq);
            h = InsereMaquinasOperacao(h, novaOperacao->idOperacao, headMaq, novaMaq->cod,novaMaq->tempo);
        }
	}

	fclose(fp);
	return h;
}


Operacoes* LimparTodaOperacao(Operacoes *listaDeOperacoes){

	Operacoes* aux = listaDeOperacoes;

	while(aux != NULL){
		aux = aux->seguinte;
		free(listaDeOperacoes);
	}
	
	return aux;
}