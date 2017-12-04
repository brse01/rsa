#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void rotina();
FILE * openFile(int operacao, char url[]);
void closeFile(FILE* arquivo);
void insert(long long int dado,long long int hash,long long msgCifrada, long long d, long long int n, char url[]);
void insertNumero(long long num, char url[]);
void read(long long int *dado,long long int *hash,long long *msgCifrada, long long *d, long long int *n, char url[]);
void readNumero(char url[], long long int *num);


// RODA O ALGORITMO EM PYTHON QUE CALCULA O SHA224.
void rotina(){
	char comando[]="python SHA224.py";	
	system(comando);
}
// FUNÇÃO PARA ABRIR UM ARQUIVO E DEPENDENDO DA NUMERAÇÃO FAZ OU ABRIR PARA ESCRITA OU PARA LEITURA
FILE * openFile(int operacao, char url[]){
FILE* arquivo;
	if(operacao==1){
		// SOBRESCREVER O ARQUIVO 
		arquivo = fopen(url,"w");
	}else{
		// LER O ARQUIVO
		arquivo = fopen(url,"r");
	}
	// CASO O ARQUIVO NÃO POSSA SER ABERTO
	if(arquivo==NULL){ 
		printf("%s\n",url);
        printf("Nao foi possivel abrir o arquivo\n");
 	    exit(0);
	}
	return arquivo;	
}

// FUNÇÃO PARA FECHAR O ARQUIVO ABERTO
void closeFile(FILE* arquivo){
	fclose(arquivo);
}

// FUNÇÃO PARA INSERIR HASH, MENSAGEM CIFRADA O VALOR D O VALOR N E A URL DO ARQUIVO
void insert(long long int dado,long long int hash,long long msgCifrada, long long d, long long int n, char url[]){
	FILE* arquivo = openFile(1,url);	
	fprintf(arquivo,"%lld %lld %lld %lld %lld",dado,hash,msgCifrada,d,n);
	closeFile(arquivo);	
}

void insertNumero(long long num, char url[]){
	FILE* arquivo = openFile(1,url);	
	fprintf(arquivo,"%lld",num);
	//printf("insertNumero[URL] %s\n",url);
	//printf("insertNumero[num] %lld\n",num);
	closeFile(arquivo);		
}

// FUNÇÃO PARA LER O HASH, MENSAGEM CIFRADA O VALOR D O VALOR N
void read(long long int *dado,long long int *hash,long long *msgCifrada, long long *d, long long int *n, char url[]){
	FILE* arquivo = openFile(2,url);		
	while((fscanf(arquivo,"%lld %lld %lld %lld %lld\n",dado,hash, msgCifrada,d,n))!=EOF ){		
	}
	printf("[Na hora da LEITURA] %lld\n",*d);
	closeFile(arquivo);
}
// FUNÇÃO QUE LER E RETORNA O NUMERO QUE ESTÁ EM UM ARQUIVO
void readNumero(char url[], long long int *num){	
	FILE* arquivo = openFile(2,url);
	while((fscanf(arquivo,"%lld\n",num))!= EOF){}

	//printf("readNumero[URL] %s \n",url);
	//printf("readNumero[num] %lld \n",num);

	closeFile(arquivo);	
}

