#define _CRT_SECURE_NO_DEPRECATE
#include "header.h"




Maquinas *CriaMaquina(int cod, char *nome,double tempo){

	// If para verificar se o codigo da maquina é valido
	if(cod < 0){
		printf("Codigo da maquina nao pode ser negativo\n");
		return NULL;
	}

	else{
		//aloca espaço de memória
		Maquinas *nova = (Maquinas*)malloc(sizeof(Maquinas));

		nova->cod = cod;
		nova->nome =  nome;
		nova->tempo = tempo;
		nova->proximoValor = NULL;
		return nova;
	}
}

Maquinas* InsereMaquinaInicio(Maquinas* inicio, Maquinas* nova) {

	if (nova == NULL) {	//se nova vem a nulo
		return inicio;
	}

	if (inicio == NULL) {	//lista vazia
		inicio = nova;
		return (inicio);
	}
	else {		
		//insere sempre no inicio
		bool valor = VerificaMaquina(inicio,nova->cod);
		// verificar se a maquina ja existe com ExisteMaquina() , se existir não inserir e imprimir mensagem, se não existir inserir.
		if( valor == 1){
			printf("Maquina %d ja existe\n",nova->cod);
			return inicio;
		}
		else{
			nova->proximoValor = inicio;
			inicio = nova;
			return inicio;
		}

	}
}

Maquinas* CalculaMinimoMaquina(Maquinas *inicio){

    Maquinas* aux = inicio;

    if(aux == NULL) return 0;

    else{

        double minimo = 0;

        while (aux != NULL)
        {

            if(minimo > aux->tempo){
                minimo = aux->tempo;               
            }
            else{
                minimo = aux->tempo;               

            }
            
           aux = aux->proximoValor;
        }
        printf("Minimo: %f",minimo);
        return aux;
    }
}

void ListarMaquinas(Maquinas *inicio) {

	Maquinas *aux = inicio;

	while (aux != NULL) {
		
		printf("ID: %d : %s : %f\n", aux->cod,aux->nome,aux->tempo);
		aux = aux->proximoValor;
	}
}

void ListaUltimo(Maquinas *inicio) {
	

	Maquinas *aux = inicio;

	while (aux != NULL) {

		aux = aux->proximoValor;
	}

	printf("O ultimo valor inserido na lista é: %d - %s - %f\n", inicio->cod, inicio->nome, inicio->tempo);

}

bool VerificaMaquina(Maquinas *inicio, int cod){

	Maquinas *aux = inicio;

	while (aux != NULL) {

		if (aux->cod == cod) {
			return true;
		}
		aux = aux->proximoValor;
	}
	return false;
}

Maquinas* GetDataMaquina(char* fileName) {
	FILE* fp;
	Maquinas* h = NULL;
    JobFile aux;
    Maquinas* novaMaq;


	char linhaFicheiro[100];

	if ((fp = fopen(fileName, "r")) == NULL) return NULL;
	
	while (fgets(linhaFicheiro,100,fp) != NULL)
		{

		// idJob;idOper;idMaq;Tempo 
		sscanf(linhaFicheiro,"%d;%d;%d;%f", &aux.j, &aux.o, &aux.m, &aux.t);

        if(VerificaMaquina(h, aux.m) == false){
            novaMaq = CriaMaquina(aux.m, "",aux.t);
            h = InsereMaquinaInicio(h, novaMaq);
        }
	}
	fclose(fp);
	return h;
}


Maquinas* LimparTodasMaquinas(Maquinas *listaDeMaquinas){

	Maquinas* aux = listaDeMaquinas;

	while(aux != NULL){
		aux = aux->proximoValor;
		free(listaDeMaquinas);
	}
	
	return aux;
}