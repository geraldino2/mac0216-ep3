#include <stdio.h>
#include <stdlib.h>
#include "libinput.h"
#include "libplot.h"

int main(int argc, char *argv[ ]) {
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
	
	char rotuloy[100] = argv[1];
	char rotulox[100] = argv[2];
	char titulo[100] = argv[3];
	
	define_titulo(titulo);
	define_rotulo_x(rotulox);
	define_rotulo_y(rotuloy);

	char **nome_linhas;
	nome_linhas = malloc(linhas * sizeof *nome_linhas);
	
	for (int i=0; i<linhas; i++){
		nome_linhas[i] = *nomelinhas+i*100;
	}

	define_nomes_linhas (nome_linhas);
	desenha_grafico (linhas, colunas,matriz);


	return 0;
}
