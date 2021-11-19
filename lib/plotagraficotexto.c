#include "libinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX 1000

bool line_titles = false;
char *gnomes_linhas[100];

void define_titulo(char *titulo) {
    FILE *fp = fopen("/tmp/gnp.cfg", "w");
    fprintf(fp, "%s \"%s\"\n", "set title", titulo);
    fclose(fp);
}

void define_rotulo_x(char *nome) {
    FILE *fp = fopen("/tmp/gnp.cfg", "a");
    fprintf(fp, "\n%s \"%s\"\n", "set xlabel", nome);
    fclose(fp);
}

void define_rotulo_y(char *nome) {
    FILE *fp = fopen("/tmp/gnp.cfg", "a");
    fprintf(fp, "\n%s \"%s\"\n", "set ylabel", nome);
    fclose(fp);
}

void define_nomes_linhas(char *nomes_linhas[]) {
	*gnomes_linhas = *nomes_linhas;
	line_titles = true;
}

void desenha_grafico(int linhas, int colunas, float planilha[][colunas]) {
    FILE *fp = fopen("/tmp/graph_data.dat", "w");
    for(int i=0;i<colunas;i++) {
    	for(int j=0;j<linhas;j++)
    		fprintf(fp,"%f ",planilha[j][i]);
    	fprintf(fp,"\n");
    }
    fclose(fp);
    FILE *gncfgfp = fopen("/tmp/gnp.cfg", "a");
    fprintf(gncfgfp,"\nset xtics 5\nset terminal dumb 100 50\n");
    if(line_titles)
    	fprintf(gncfgfp, "\nplot '/tmp/graph_data.dat' u 1:2 title '%s' w lp\\\n", *gnomes_linhas+100);
    else
    	fprintf(gncfgfp, "\nplot '/tmp/graph_data.dat' u 1:2 w lp\\\n");
    for(int i=1;i<colunas-1;i++) {
    	if(line_titles)
    		fprintf(gncfgfp, ",'/tmp/graph_data.dat' u 1:%d title '%s' w lp\\\n", i+2, *gnomes_linhas+100+i*100);
    	else
    		fprintf(gncfgfp, ",'/tmp/graph_data.dat' u 1:%d w lp\\\n", i+2);
    }
    fprintf(gncfgfp, "\n");
    fclose(gncfgfp);
    char *argv[5] = {"gnuplot", "-p", "<", "/tmp/gnp.cfg", NULL};
    execvp("gnuplot", argv);
}
