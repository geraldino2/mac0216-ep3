#include "libinput.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#define MAX 1000

void carrega_dados (char *caminho_dos_dados, int *linhas, int *colunas, void **planilha, char **nomes_linhas[]){
    //Baixar planilha da WEB:
    CURLcode res;
    char *filename = "../planilha.csv";
    CURL *curl = curl_easy_init();
    FILE *file = fopen(filename, "w+b");
    if (curl) {
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
    char * line = NULL;
    size_t len = 0;
    char nomesLinhas[MAX][100];

    while (getline(&line, &len, fp) != -1){
        int column = 0;
        char *word;
        
        while (word = strsep(&line,",")){
            if(column == 0) strcpy(nomesLinhas[*linhas], word);
            else {
                float x = atof(word);
                table[*linhas][column-1] = x;
            }
            column++;
        }
        *colunas = column-1;
        
        *linhas= *linhas + 1;
    }

    fclose(file);
    float p[*linhas][*colunas];

    for (int i=0; i< *linhas; i++){
        for (int j= 0; j< *colunas; j++){
            p[i][j] = table[i][j];
        }
    }
    *planilha = (void *) (float **) p;
    *nomes_linhas = nomesLinhas;
}

int main(int argc, char const *argv[])
{   
    int colunas, linhas;
    void *planilha;

    char *nomelinhas[100];
    carrega_dados("https://www.ime.usp.br/~kon/tmp/BRICS_PIBPerCapita.csv",&linhas ,&colunas, &planilha, &nomelinhas);
    
    float matriz[linhas][colunas];
    for (int j=0; j<linhas;j++){
        for(int i=0; i<colunas;i++){
            matriz[j][i]= *((float*)planilha+(j*colunas)+i);
        }
    }
    for (int i=0; i<linhas;i++) printf("%s\n", *nomelinhas+i*100);
}

