#include "libinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000

char *cmd = "";
bool open_gnu = false;
//FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
FILE *gnuplotPipe;
void ognu()
{
    gnuplotPipe = popen("gnuplot -persistent", "w");
    open_gnu = true;
}

void define_titulo(char *titulo)
{
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set title", titulo);
}
void define_rotulo_x(char *nome)
{
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set xlabel", nome);
}
void define_rotulo_y(char *nome)
{
    if (!(open_gnu))
    {
        ognu();
    }
    fprintf(gnuplotPipe, "%s \"%s\" \n", "set ylabel", nome);
}
void define_nomes_linhas(char *nomes_linhas[])
{
    if (!(open_gnu))
    {
        ognu();
    }
    int linhas;
    for (int i = 0; i < linhas; i++)
        printf("%s\n", *nomes_linhas + i * 100);
}
void desenha_grafico(int linhas, int colunas, float planilha[][colunas])
{
    if (!(open_gnu))
    {
        ognu();
    }
    char *x_range[colunas + 2];
    x_range[0] = "(";
    x_range[2 * colunas] = ")";
    fprintf(gnuplotPipe, "%s", "set xtics (");
    for (int i = 0; i < colunas; i++)
    {
        fprintf(gnuplotPipe, "%f %s ", planilha[0][i], ",");
    }
    fprintf(gnuplotPipe, "%s \n", ")");
    FILE *temp = fopen("data.temp", "w");
}

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void **planilha, char **nomes_linhas[])
{
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

int main(int argc, char const *argv[])
{
    int colunas, linhas;
    void *planilha;

    char *nomelinhas[100];
    carrega_dados("https://www.ime.usp.br/~kon/tmp/BRICS_PIBPerCapita.csv", &linhas, &colunas, &planilha, &nomelinhas);

    float matriz[linhas][colunas];
    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < colunas; i++)
        {
            matriz[j][i] = *((float *)planilha + (j * colunas) + i);
        }
    }
    // for (int i = 0; i < linhas; i++)
    //     printf("%s\n", *nomelinhas + i * 100);
    define_titulo("teste");
    desenha_grafico(linhas, colunas, matriz);
    int k = 0;
}
