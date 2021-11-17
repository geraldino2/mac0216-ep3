#include <stdio.h>
//#include "libinput.h"
//#include "libplot.h"

int main() {
	printf("Informe o caminho para o arquivo csv: ");
	char path[100];
	scanf("%[^\n]", path);

	int colunas, linhas;
    void *planilha;
	char *nomelinhas[100];
	
	carrega_dados(path,&linhas ,&colunas, &planilha, &nomelinhas);

	float matriz[linhas][colunas];
    for (int j=0; j<linhas;j++){
        for(int i=0; i<colunas;i++){
            matriz[j][i]= *((float*)planilha+(j*colunas)+i);
        }
    }
	char rotuloy[100], rotulox[100];
	printf("Qual o rotulo das abcissas?");
	scanf("%[^\n]", rotulox);
	printf("E das ordenadas?");
	scanf("%[^\n]", rotuloy);

	char **nome_linhas;
	nome_linhas = malloc(linhas * sizeof *nome_linhas);
	
	for (int i=0; i<linhas; i++){
		nome_linhas[i] = *nomelinhas+i*100;
	}

	//Plota gráfico


	return 0;
}