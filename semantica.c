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
    
    //fscanf();
    
    fclose(abrir);
	fclose(saida);
	free(entrada);
    
    system("PAUSE");
    return 0;
}
