#!/usr/bin/python3

import networkx as nx
import numpy as np
import sys
import datetime

def ler_grafo(arquivo):
    arq = open(arquivo, 'r')
    texto = arq.readlines()
    G = nx.Graph()
    for linha in texto:
        if(linha[0] == 'c' or linha[0] == 'p'):
            continue
        linha = linha.replace("\n", "")
        partes = linha.split(" ")
        G.add_edge(partes[1], partes[2])

    arq.close()

    return G


g = ler_grafo(sys.argv[1])

start = datetime.datetime.now()
result = nx.greedy_color(g, strategy='DSATUR', interchange=False)
end = datetime.datetime.now()
elapsed = end - start

cores = list(result.values())
#print("Arquivo: " + str(sys.argv[1]) + "\n")
if(len(sys.argv) == 3 and sys.argv[2] == 'm'):
    print(';' + str(len(np.unique(cores)))+";"+str(int(elapsed.total_seconds()*1000)))
else:
    print("Numero de cores encontradas: " + str(len(np.unique(cores))))
