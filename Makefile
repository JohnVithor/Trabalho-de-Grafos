# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Comandos do sistema operacional
RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all clean distclean doxy

all: dir DSATUR

debug: CFLAGS += -g -O0 -pg
debug: dir DSATUR

DSATUR: $(OBJ_DIR)/GraphReader.o $(OBJ_DIR)/main.o 
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel DSATUR criado em $(BIN_DIR)]"
	
$(OBJ_DIR)/Coloration.o: $(SRC_DIR)/Coloration.cpp $(INC_DIR)/Coloration.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/Graph.o: $(SRC_DIR)/Graph.cpp $(INC_DIR)/Graph.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/Node.o: $(SRC_DIR)/Node.cpp $(INC_DIR)/Node.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/GraphReader.o: $(SRC_DIR)/GraphReader.cpp $(INC_DIR)/GraphReader.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
dir:
	mkdir -p bin build doc

# Alvo (target) para analisar o código em busca de vazamento de memória (modo 1)
valgrind_simple:
	valgrind -v  $(arg1) $(arg2) $(arg3) $(arg4)

# Alvo (target) para analisar o código em busca de vazamento de memória (modo 2)
valgrind_full:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes $(arg1) $(arg2) $(arg3) $(arg4)

# Alvo (target) usado para analise estatica do código. (modo 1)
# analisa o arquivo indicado por arg1 - modo de usar: make lint_complete arg1=_caminho-do-arquivo_
# substituir _caminho-do-arquivo_ pelo caminho do arquivo.
lint_complete:
	python2 cpplint.py --headers=hpp $(arg1)
	
# Alvo (target) usado para analise estatica do código. (modo 2)
# analisa o arquivo indicado por arg1 e filtra erros de tamanho da linha e de referencias
# - modo de usar: make lint_complete arg1=_caminho-do-arquivo_
# substituir _caminho-do-arquivo_ pelo caminho do arquivo.
lint:
	python2 cpplint.py --filter=-runtime/references,-whitespace/line_length --headers=hpp $(arg1)

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

