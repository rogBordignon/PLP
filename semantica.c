#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ls;
    char rs;
    FILE *abrir;
	FILE *saida;

    brir = fopen("entrada.txt","r");
	saida = fopen("saida.txt","w");
    
    //fscanf(); E necessario conhecer o formato das linhas da analise sintatica para poder implantar a operacao de leitura.
    
    fclose(abrir);
	fclose(saida);
	free(entrada);
    
    system("PAUSE");
    return 0;
}
