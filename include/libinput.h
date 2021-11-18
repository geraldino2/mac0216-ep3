#ifndef _libinput_h
#define _libinput_h

/*
 * Função: carrega_dados
 * Uso: carrega_dados(caminho_dos_dados, &linhas, &colunas, &planilha, &nome_linhas)
 * ----------------------------------
 * Esta função devolve o tamanho da planilha correspondente nos parâmetros de saída
 * *linhas e *colunas, um apontador para a posição de memória da planilha e outro apontador
 * para um vetor de strings contendo os nomes das linhas em nomes_linhas.
 *  
*/

void carrega_dados (char *caminho_dos_dados, int *linhas, int *colunas, void **planilha, char **nomes_linhas[]);

#endif