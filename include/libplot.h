#ifndef _libinput_h
#define _libinput_h

/**
 * Função: define_titulo
 * Uso: 
 * ------------------------
 * 
 */
void define_titulo (char *titulo);

/**
 * Função: define_rotulo_x
 * Uso: 
 * ------------------------
 * 
 */
void define_rotulo_x (char *nome);

/**
 * Função: define_rotulo_y
 * Uso: 
 * ------------------------
 * 
 */
void define_rotulo_y (char *nome);

/**
 * Função: define_nomes_linhas
 * Uso: 
 * ------------------------
 * 
 */
void define_nomes_linhas (char *nomes_linhas[]);

/**
 * Função: desenha_grafico
 * Uso: 
 * ------------------------
 * 
 */
void desenha_grafico (int linhas, int colunas, float planilha[][colunas]);

#endif