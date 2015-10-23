#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct an
{
	char token[100];
	char tipo [100];
	char linha[100];
}analise;

int main()
{


	FILE *abrir;
	FILE *saida;
	int flag=0;
	
	flag = analise_lexica(abrir,saida);
	if(flag==0)
	{
		analise_sintatica(saida);
	}
	
	flag = analise_sintatica(saida);
	if(flag==0)
	{
		analise_semantica(saida);
	}
	
	system("PAUSE");
	return 0;
}

void analise_semantica(FILE *saida)
{
	int i=0, j=0, contadorToken=0, flag=0, percorre=0, sentinela=0, imprime=0, k=0, auximprime=0;
	char *entrada;
	char caracter, c;
	analise semantica[1000];
	char resposta[100]={};
	char aux[100]={};
	saida = fopen("saida.txt","r");
	
	if(saida == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	
	entrada = malloc(sizeof(char)*2000);
	
	
	while((caracter=fgetc(saida))!=EOF)
	{
		entrada[i]=caracter;
		i++;
	}
		entrada[i]='\0';
        
        while(j<strlen(entrada))
        {
		c=entrada[j];

        	token:
			while(isalpha(c) || isdigit(c) || ispunct(c))
			{
				sprintf(aux, "%c", c);
        			strcat(resposta,aux);
        			j=j+1;
        			c=entrada[j];
			}
        		if(flag == 0)
        		{
        			strcpy(sintatica[contadorToken].token,resposta);
        			flag=1;
        			memset(&resposta[0], 0, sizeof(resposta));
        			memset(&aux[0], 0, sizeof(aux));
        			goto avanca;
        		}
        		if(flag == 1)
        		{
				strcpy(sintatica[contadorToken].tipo,resposta);
        			flag=2;
        			memset(&resposta[0], 0, sizeof(resposta));
        			memset(&aux[0], 0, sizeof(aux));
        			goto avanca;
        		}
        		if(flag == 2)
        		{
        			strcpy(sintatica[contadorToken].linha,resposta);
        			flag=0;
        			memset(&resposta[0], 0, sizeof(resposta));
        			memset(&aux[0], 0, sizeof(aux));
        			contadorToken += 1;
        			goto avanca;
        		}
		avanca:
			while(c ==  32 || c == 9)
        		{
				j = j+1;
        			c = entrada[j];
        		}
        		if(c == 10)
        		{
        			j = j+1;
        			c = entrada[j];
        			goto token;
        		}

        		if(c == 0)
        		{
        			strcpy(sintatica[contadorToken].token,"#");
        			strcpy(sintatica[contadorToken].tipo,"#");
        			strcpy(sintatica[contadorToken].linha,"#");
        			break;
        		}
        	goto token;

	}
        
        
	/**/
	
	analisa:
	if(sentinela == 0)
	{
		erro_sintatico:
        	printf("\n\nERRO SINTATICO - LINHA:%s\n",sintatica[percorre].linha);
    	}
    	
    	else
        	printf("\	n\nSEM NENHUM ERRO SINTATICO\n");

	fclose(saida);
}
