# EP 3 - Bibliotecas, bibliotecas, bibliotecas

## Descrição do exercício
Um sistema capaz de plotar gráficos de linhas a partir de dados brutos; É possível, também, definir o título do gráfico, rótulo dos eixos e identificadores para as linhas.  A partir das bibliotecas estáticas implementadas é possível ter uma saída em .png ou uma saída por texto; A partir das dinâmicas, é possível carregar dados localmente ou baixando um arquivo da web.
\
\
O [`Makefile`](https://github.com/geraldino2/mac0216-ep3/blob/main/lib/Makefile) gera 4 executáveis, combinações possíveis das bibliotecas dinâmicas e estáticas. Os executáveis devem ser executados no formato `./executavel titulo eixo_x eixo_y `. Pode vir a ser necessário executar o seguinte comando antes de um `make all`: `export LD_LIBRARY_PATH=path/to/lib:$PWD`.
\
\
É possível testar os programas com os seguintes arquivos de exemplo:
* [BRICS_PibPerCapita](http://www.ime.usp.br/~kon/tmp/BRICS_PIBPerCapita.csv)
* [BRICS_ExportacaoTecnologica](http://www.ime.usp.br/~kon/tmp/BRICS_ExportacaoTecnologica.csv)
* [BRICS_ExpectativaDeVida](http://www.ime.usp.br/~kon/tmp/BRICS_ExpectativaDeVida.csv)
* [BRICS_MortalidadeInfantil](http://www.ime.usp.br/~kon/tmp/BRICS_MortalidadeInfantil.csv)
* [BRICS_EmissaoDeCO2PerCapita](http://www.ime.usp.br/~kon/tmp/BRICS_EmissaoDeCO2PerCapita.csv)
* [BRICS_TaxaDeFertilidade](http://www.ime.usp.br/~kon/tmp/BRICS_TaxaDeFertilidade.csv)

## TODO
- [X] Biblioteca de leitura de um arquivo do computador
- [X] Biblioteca de leitura de um arquivo da Web
- [X] Biblioteca de interface gráfica com texto puro
- [X] Biblioteca de interface gráfica com gnuplot
- [X] Main unindo as 4 bibliotecas
- [X] Script Makefile
- [ ] Biblioteca de interface gráfica com plot em janela adicional (OPCIONAL)
