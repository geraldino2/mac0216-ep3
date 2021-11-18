#include "libinput.h"
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
FILE *gnuplotPipe;

void ognu() {
    gnuplotPipe = popen("gnuplot -p", "w");
    open_gnu = true;
}

void define_titulo(char *titulo) {
    if (!(open_gnu))  ognu();
    fprintf(gnuplotPipe, "%s \"%s\"\n", "set title", titulo);
}

void define_rotulo_x(char *nome) {
    if (!(open_gnu))  ognu();
    fprintf(gnuplotPipe, "%s \"%s\"\n", "set xlabel", nome);
}

void define_rotulo_y(char *nome) {
    if (!(open_gnu))  ognu();
    fprintf(gnuplotPipe, "%s \"%s\"\n", "set ylabel", nome);
}

void define_nomes_linhas(char *nomes_linhas[]) {
	*gnomes_linhas = *nomes_linhas;
	line_titles = true;
}

void desenha_grafico(int linhas, int colunas, float planilha[][colunas]) {
    if (!(open_gnu))  ognu();
    FILE *fp = fopen("graph_data.dat", "w");
    for(int i=0;i<colunas;i++) {
    	for(int j=0;j<linhas;j++)
    		fprintf(fp,"%f ",planilha[j][i]);
    	fprintf(fp,"\n");
    }
    fprintf(gnuplotPipe,"set xtics 5\nset terminal x11\nset output 'graph.png'\n");
    if(line_titles)
    	fprintf(gnuplotPipe, "plot 'graph_data.dat' u 1:2 title '%s' w lp\\\n", *gnomes_linhas+100);
    else
    	fprintf(gnuplotPipe, "plot 'graph_data.dat' u 1:2 w lp\\\n");
    for(int i=1;i<colunas-1;i++) {
    	if(line_titles)
    		fprintf(gnuplotPipe, ",'graph_data.dat' u 1:%d title '%s' w lp\\\n", i+2, *gnomes_linhas+100+i*100);
    	else
    		fprintf(gnuplotPipe, ",'graph_data.dat' u 1:%d w lp\\\n", i+2);
    }
    fprintf(gnuplotPipe, "\n");
}
