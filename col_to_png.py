import networkx as nx
import matplotlib.pyplot as plt
from random import random
import sys

if(len(sys.argv) != 3):
    print("Modo de Uso:\n Informe primeiro o col do grafo e o nome do arquivo com a coloração\n")
    print("Exemplo: python col_to_png Turmas/2018.2.col Turmas/2018.2.color")
    exit()


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

def let_coloracao(arquivo):
    arq = open(arquivo, 'r')
    texto = arq.readlines()
    C = dict()
    for linha in texto:
        if(linha == "\n"):
            return C
        
        linha = linha.replace("\n", "")
        partes = linha.split(" : ")
        C[partes[0]] = int(partes[1])

    arq.close()

    return C

g = ler_grafo(sys.argv[1])
r = let_coloracao(sys.argv[2])

maximum = max(r, key=r.get)
colors = dict()
for i in range(int(r[maximum])+1):
    colors[str(i)] = (random(), random(), random())
co = [ (colors[str(r[i])]) for i in list(g.nodes())]

nx.draw_kamada_kawai(g, node_color=co)
#nx.draw(g, node_size=20, node_color=co)
plt.savefig("grafo colorido")