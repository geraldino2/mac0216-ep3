//#include "libinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000

char *cmd = "";
bool open_gnu = false;
bool line_titles = false;
char *gnomes_linhas[100];
//FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
FILE *gnuplotPipe;
void ognu() {
    gnuplotPipe = popen("gnuplot -p", "w");
    open_gnu = true;
}

void define_titulo(char *titulo) {
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set title", titulo);
}
void define_rotulo_x(char *nome) {
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set xlabel", nome);
}
void define_rotulo_y(char *nome) {
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set ylabel", nome);
}
void define_nomes_linhas(char *nomes_linhas[]) {
	*gnomes_linhas = *nomes_linhas;
}
void desenha_grafico(int linhas, int colunas, float planilha[][colunas]) {
    if (!(open_gnu))  ognu();
    FILE *fp = fopen("graph_data.dat", "w");
    for(int i=0;i<colunas;i++) {
    	for(int j=0;j<linhas;j++)
    		fprintf(fp,"%f ",planilha[j][i]);
    	fprintf(fp,"\n");
    }
    //printf("%s",*gnomes_linhas);
    fprintf(gnuplotPipe,"set terminal png\nset output 'graph.png'\n");
    fprintf(gnuplotPipe, "plot 'graph_data.dat' u 2:xtic(1) title '%s' w lp\n", *gnomes_linhas+100);
    fflush(gnuplotPipe);
    for(int i=1;i<colunas-1;i++) {

    }
}

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void **planilha, char **nomes_linhas[]) {
    //Baixar planilha da WEB:
    CURLcode res;
    char *filename = "../planilha.csv";
    CURL *curl = curl_easy_init();
    FILE *file = fopen(filename, "w+b");
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, caminho_dos_dados);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(file);

    //Ler planilha:
    FILE *fp = fopen("../planilha.csv", "r");
    float table[MAX][MAX];
    *colunas = *linhas = 0;
    char *line = NULL;
    size_t len = 0;
    char nomesLinhas[MAX][100];

    while (getline(&line, &len, fp) != -1)
    {
        int column = 0;
        char *word;

        while (word = strsep(&line, ","))
        {
            if (column == 0)
                strcpy(nomesLinhas[*linhas], word);
            else
            {
                float x = atof(word);
                table[*linhas][column - 1] = x;
            }
            column++;
        }
        *colunas = column - 1;

        *linhas = *linhas + 1;
    }

    fclose(file);
    float p[*linhas][*colunas];

    for (int i = 0; i < *linhas; i++)
    {
        for (int j = 0; j < *colunas; j++)
        {
            p[i][j] = table[i][j];
        }
    }
    *planilha = (void *)(float **)p;
    *nomes_linhas = nomesLinhas;
}

int main(int argc, char const *argv[]) {
    int colunas, linhas;
    void *planilha;

    char *nomelinhas[100];
    carrega_dados("https://www.ime.usp.br/~kon/tmp/BRICS_PIBPerCapita.csv", &linhas, &colunas, &planilha, &nomelinhas);

    float matriz[linhas][colunas];
    for (int j = 0; j < linhas; j++)
        for (int i = 0; i < colunas; i++)
            matriz[j][i] = *((float *)planilha + (j * colunas) + i);
    //for (int i = 1; i <	linhas; i++) printf("%s\n", *nomelinhas + i * 100);
    //define_titulo("teste");
    define_nomes_linhas(nomelinhas);
    desenha_grafico(linhas, colunas, matriz);
    int k = 0;
}
