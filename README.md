# Trabalho-de-Grafos

## Requisitos
- gcc
- python3
- matplotlib
- numpy
- pandas

Para instalar os requisitos do python basta rodar o script:

`./requirements.sh`

## Compilar o programa C++
 basta executar o arquivo Makefile:

`make`

Isso irá gerar o executável na pasta `/bin/` com no DSATUR.

## Executando o programa C++
 
Um exemplo de execução do programa seria:

`./bin/DSATUR -i arquivo.col -m >> resultado.csv`

Esse programa irá gerar no arquivo resultado.csv os seguintes campos nessa ordem:
- Tamanho: o número de arestas do grafo
- Tempo: o tempo que o programa demorou para executar
- Número cromático: o número cromático encontrado
- Número cromático ótimo: o número cromático mínimo

## Resultado

Para visualizar o resultado obtido como exemplo temos o arquivo `Sigraade.py` com uma interface ncurses que mostra os conjuntos de disciplinas obtidos.
Bastar executar:

`python3 Sigraade.py`
