#include "libinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void carrega_dados (char *caminho_dos_dados, int *linhas, int *colunas, void **planilha, char **nomes_linhas[]) {
	float planilha_template[MAX][MAX];
	char nomes_linhas_template[MAX][100];
	char *linha, *coluna;
	int i=0, j;
	size_t len;
	FILE *arqptr = fopen(caminho_dos_dados, "r");
	while (getline(&linha, &len, arqptr) != -1) {
		j = 0;
		while(coluna = strsep(&linha,",")) {
			if(j==0) {
				strcpy(nomes_linhas_template[i], coluna);
			} else {
				planilha_template[i][j-1] = atof(coluna);
			}
			j++;
		}
		i++;
	}
	*linhas = i;
	*colunas = j-1;
	float p[*linhas][*colunas];
	for(int i=0; i<*linhas; i++){
		for(int j=0; j<*colunas; j++){
			p[i][j] = planilha_template[i][j];
		}
	}
	*planilha = (void *)(float **)p;
	*nomes_linhas = nomes_linhas_template;
	fclose(arqptr);
}

int main() {
	void *planilha;
	int r, c;
	char *nome_linhas[100];
	char *url = "BRICS_PIBPerCapita.csv";
	carrega_dados(url, &r, &c, &planilha, &nome_linhas);
	float matriz[r][c];
	for (int i=0; i<r;i++){
		printf("%s ", *nome_linhas+i*100);
		for(int j=0; j<c;j++){
			matriz[i][j] = *((float*) planilha+(i*c)+j);
			printf("%f ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
