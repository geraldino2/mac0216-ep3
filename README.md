# EP 3 - Bibliotecas, bibliotecas, bibliotecas

## Descrição do exercício
Um sistema capaz de plotar gráficos de linhas a partir de dados brutos; É possível, também, definir o título do gráfico, rótulo dos eixos e identificadores para as linhas.  A partir das bibliotecas estáticas implementadas é possível ter uma saída em .png ou uma saída por texto; A partir das dinâmicas, é possível carregar dados localmente ou baixando um arquivo da web.
\
\
O `Makefile` aqui presente gera os 4 executáveis, combinações possíveis das bibliotecas dinâmicas e estáticas.
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
- [ ] Main unindo as 4 bibliotecas
- [X] Script Makefile
- [ ] Biblioteca de interface gráfica com plot em janela adicional (OPCIONAL)
