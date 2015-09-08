/*
	PLP - Analisador LÃ©xico
	
	GRUPO
	
	Erik Volpert
	Gustavo Santarsieri
	Rogerio Bordignon
	Yuri Serrano
	
	
*/



/*
  Por Yuri Serrano
  
  Boa Noite Pessoal
  
  Sempre que fizerem alteracoes no codigo coloquem o seu nome e o que foi feito 
  para outros membros nao acabarem realizando a toa, caso dois facam a mesma coisa no mesmo tempo
  joguem na mega sena um dos dois ira ganhar eu garanto.
  
  
  Nessa primeira parte eu fiz o sistema de leitura do arquivo, em que eu uso o fgetc que pega cada caracter do arquivo de entrada
  e armazena em um vetor de chars alocado dinamicamente.
  Eu havia feito uma versao otimizada, porem depois eu li que seria necessario o uso da etapa anterior entao nesta primeira versao
  estaremos utilizando goto para simular a transicao dos estados, basicamente todosos bugs da leitura de arquivo eu ja¡ solucionei,falta
  apenas um que eh o de espacos demasiados no arquivo , mas de resto esta tudo ok.
  Desta parte o arquivo de entrada tras o codigo sim e retorna o TOKEN TIPO LINHA em que foi pego exemplo:
  
  escreva     Palavra Reservada   1
  
  
  Agora so precisamos fazer o cadastro dos autamatos e esta tudo certo.
  
  Eu ja cadastrei as palavras reservadas:
  
  enquanto - OK
  entao - OK
  e - OK
  escreva -OK
  ou - OK
  booleano - OK
  retorne - OK
  leia - OK
  se - OK
  senao - OK
  
  Faltam algumas e tambem algumas classes de identificacao que sao:
  
  programa 
  procedimento
  
  var
  verdadeiro
  
  
  inicio
  inteiro  
  
  
  faca
  funcao
  fim
  falso
  
  
  
  Classe dos identificadores (L  (D|L|_) )
  
  Classe dos Operadores Relacionais ( < >  <> <= >= )
  
  Classedos delimitadores (. , ; )
  
  Como exemplo basta analisar o codigo que eu ja produzi que conseguiram realizar sem problema.
  
  Tiramos 10 na primeira etapa, mas a dani fez observacoes co os identificadores < > entao eu ja fiz a correcao do automato e o correto estara
  aqui no github.
  
  
  Bom trabalho a todos.
  
  
  Nao esquecam de comentar no codigo o que foi produzido
  
Para testar o que foi feito eh preciso ter um arquivo chamado entrada.txt , o de saida eh gerado automaticamente.  


ATTE Yuri Serrano


OBS:

Links interessantes:

http://web.cs.mun.ca/~michael/c/ascii-table.html
http://www.tutorialspoint.com/c_standard_library/ctype_h.htm
http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/

*/




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


int main()
{
	
	char *entrada;
	char resposta[100]  ={};
	FILE *abrir;
	FILE *saida;
	int i=0,contador,linha=1,j=0;
	char caracter,c;
	abrir = fopen("entrada.txt","r");
	saida = fopen("saida.txt","w");
	
	if(abrir == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
			
	if(saida == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");		
	
	
	
	fprintf(saida,"TOKEN\t\t\t\t\tTIPO\t\t\t\t\t\tLINHA\n");
	entrada = malloc(sizeof(char)*2000);
	
	// Lê todos os caractres do arquivo para o vvetor entrada[].
	while((caracter=fgetc(abrir))!=EOF) 
	{
		entrada[i]=caracter;
		i++;
	}
	
	printf(" [0]:%d\n [1]:%d\n [2]:%d\n [3]:%d\n [4]:%d\n [5]:%d\n [6]:%d\n [7]:%d\n [8]:%d\n",entrada[0],entrada[1],entrada[2],entrada[3],entrada[4],entrada[5],entrada[6],entrada[7],entrada[8]);
	
	entrada[i]='\0';

	while(j<strlen(entrada))
	{	
	
	
		
		inicio:
		memset(&resposta[0], 0, sizeof(resposta));
		c=entrada[j];
		identificador:
		
		/*
		 *  
		*/
		if(isalpha(c) && c == 'e' && c == 101) 
		{
			
			if(isspace(entrada[j+1]) || entrada[j+1] ==  32 || entrada[j+1] == 10 || entrada[j+1] == '\0')
			{
				strcat(resposta,"e");
				
				//printf("%s",resposta);			
				fprintf(saida,"%s\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+1] == 10)
					linha=linha+1;
				j=j+2;
				goto inicio;			
								
			}
			if(isalpha(entrada[j+1]) && entrada[j+1] == 's' && entrada[j+1] == 115)
			{
				strcat(resposta,"e");
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"s");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"s");
				j=j+1;
				goto escreva;
				
			}
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'n' && entrada[j+1] == 110)
			{
				strcat(resposta,"e");
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"n");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"n");
				j=j+1;
				if(entrada[j+1] == 'q')
					goto enq;
				if(entrada[j+1] == 't')
					goto prox;
				
				
			}
			prox:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 't' && entrada[j+1] == 116)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"t");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"t");
				j=j+1;
				goto entao;
			}
			enq:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'q' && entrada[j+1] == 113)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"q");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"q");
				j=j+1;
				goto enquanto;
			}
			entao:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"a");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"a");
				j=j+1;
				goto entao1;
			}
			entao1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				strcat(resposta,"o");
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
				
			}
			enquanto:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'u' && entrada[j+1] == 117)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"u");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"u");
				j=j+1;
				goto enquanto1;
			}	
			enquanto1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"a");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"a");
				j=j+1;
				goto enquanto2;
			}
			enquanto2:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'n' && entrada[j+1] == 110)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"n");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"n");
				j=j+1;
				goto enquanto3;
			}
			enquanto3:
				printf("%c - %d\n",entrada[j+1],entrada[j+1]);
			if(isalpha(entrada[j+1]) && entrada[j+1] == 't' && entrada[j+1] == 116)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"t");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"t");
				j=j+1;
				goto enquanto4;
			}
			enquanto4:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				strcat(resposta,"o");
				fprintf(saida,"%s\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
				
			}
			escreva:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'c' && entrada[j+1] == 99)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"c");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"c");
				j=j+1;
				goto escreva1;
				
			}
			escreva1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'r' && entrada[j+1] == 114)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"r");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"r");
				j=j+1;
				goto escreva2;
				
			}
			escreva2:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"e");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"e");
				j=j+1;
				goto escreva3;
				
			}
			escreva3:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'v' && entrada[j+1] == 118)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"v");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"v");
				j=j+1;
				goto escreva4;
				
			}
			escreva4:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					strcat(resposta,"a");
					j = j+2;
					goto identificador;
				}
				strcat(resposta,"a");
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
				
			}
				
			
		}
		if(isalpha(c) && c == 'o' && c == 111) 
		{
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'u' && entrada[j+1] == 117)
			{
				strcat(resposta,"o");
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				strcat(resposta,"u");
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
				
			}
		}
	
		if(isalpha(c) && c == 'l' && c == 108) 
		{
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				strcat(resposta,"l");
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"e");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"e");
				j=j+1;
				goto leia;
							
			}
			leia:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'i' && entrada[j+1] == 105)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"i");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"i");
				j=j+1;
				goto leia1;
				
			}
			leia1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				strcat(resposta,"a");
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
			}
			
			
		}
		if(isalpha(c) && c == 'b' && c == 98) 
		{
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				strcat(resposta,"b");
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"o");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"o");
				j=j+1;
				goto booleano;
							
			}
			booleano:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"o");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"o");
				j=j+1;
				goto booleano1;
				
			}
			booleano1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'l' && entrada[j+1] == 108)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"l");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"l");
				j=j+1;
				goto booleano2;
			}
			booleano2:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"e");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"e");
				j=j+1;
				goto booleano3;
			}
			booleano3:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"a");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"a");
				j=j+1;
				goto booleano4;
			}
			booleano4:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'n' && entrada[j+1] == 110)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"n");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"n");
				j=j+1;
				goto booleano5;
			}
			booleano5:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				strcat(resposta,"o");
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				
				fprintf(saida,"%s\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
			}		
			
		}
		
		if(isalpha(c) && c == 'r' && c == 114) 
		{
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				strcat(resposta,"r");
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"e");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"e");
				j=j+1;
				goto retorne;
							
			}
			retorne:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 't' && entrada[j+1] == 116)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"t");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"t");
				j=j+1;
				goto retorne1;
				
			}
			retorne1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"o");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"o");
				j=j+1;
				goto retorne2;
				
			}
			retorne2:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'r' && entrada[j+1] == 114)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"r");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"r");
				j=j+1;
				goto retorne3;
				
			}
			retorne3:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'n' && entrada[j+1] == 110)
			{
				
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"n");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"n");
				j=j+1;
				goto retorne4;
				
			}
			retorne4:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				strcat(resposta,"e");
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
			}
		}
		if(isalpha(c) && c == 's' && c == 115)		 
		{
			strcat(resposta,"s");
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'e' && entrada[j+1] == 101)
			{
				strcat(resposta,"e");
				if(entrada[j+2] == 'n')
				{
					j=j+1;
					goto senao;
				}
				if(isalpha(entrada[j+2])  || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
				
			}
			senao:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'n' && entrada[j+1] == 110)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"n");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"n");
				j=j+1;
				goto senao1;
			}
			senao1:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'a' && entrada[j+1] == 97)
			{
				if(entrada[j+2] == 32 || entrada[j+2] == 10 || entrada[j+2] == '\0')
				{
					strcat(resposta,"a");
					j = j+3;
					goto identificador;
				}
				strcat(resposta,"a");
				j=j+1;
				goto senao2;
			}
			senao2:
			if(isalpha(entrada[j+1]) && entrada[j+1] == 'o' && entrada[j+1] == 111)
			{
				strcat(resposta,"o");
				if(isalpha(entrada[j+2]) || isdigit(entrada[j+2]) )
				{
					j = j+2;
					goto identificador;
				}
				
				fprintf(saida,"%s\t\t\t\t\tPalavra Reservada\t\t\t\t%d\n",resposta,linha);
				if(entrada[j+2] == 10 || entrada[j+2] == 32 || entrada[j+2] == '\0')
				{
					if(entrada[j+2] == 10)
						linha=linha+1;
					j = j+3;
					goto inicio;
					
				}
			}
							
			
		}
		
		if(entrada[j+1] == '\0')
			break;
			
}
//	printf("entrada[%d]:%d\n entrada[%d]:%d\n  entrada[%d]:%d\n  entrada[%d]:%d\n entrada[%d]:%d\n",0,entrada[0],1,entrada[1],2,entrada[2],3,entrada[3],4,entrada[4]);
	
	fclose(abrir);
	fclose(saida);
	free(entrada);
	
	system("PAUSE");
	return 0;
}

