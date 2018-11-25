import pandas as pd
import networkx as nx
import sys

if(len(sys.argv) != 3):
    print("Modo de Uso:\n Informe primeiro o csv de origem e o nome do arquivo de destino\n")
    print("Exemplo: python csv_to_col Turmas/2018.2.csv 2018.2")
    exit()


# Compara se dois horários tem mesmo turno
def comp_t(hor1, hor2):
    turno = ['M', 'T', 'N']
    for t in turno:
        h1 = hor1.find(t)
        h2 = hor2.find(t)
        if (h1 > 0 and h2 > 0):
            return t
    return 'F'


# Compara se há confilto entre horários
def comp(hor1, hor2):
    turno = comp_t(hor1, hor2)
    if (turno == 'F'):
        return False

    w1, h1 = hor1.split(turno)
    w2, h2 = hor2.split(turno)

    for d1 in w1:
        if (d1 in w2):
            for h in h1:
                if(h in h2):
                    return True
    return False


turmas = pd.read_csv(sys.argv[1])
# Retira as turmas não atendidas
turmas = turmas[turmas["Situação"] == "Atendida"]
# Reseta os índices do dataFrame
turmas = turmas.reset_index().drop('index', axis=1)
# Formata a coluna Horário para retirar a data. Ex: "24T12 (1/1/2018 - 12/12/2018)" -> "24T12"
turmas['Horário'] = turmas['Horário'].str.split(expand=True)[0]

g = nx.Graph()
n = len(turmas['Horário'])
for i in range(n):
    for j in range(i, n):
        if ((turmas['Horário'][i] != turmas['Horário'][j]) and not comp(turmas['Horário'][i], turmas['Horário'][j])):
            g.add_edge(i, j)

file = open("Turmas/" + sys.argv[2] + ".col", 'w')
file.write("c FILE: " + sys.argv[2] + ".col\n")
file.write("c SOURCE: SIGAA (UFRN)\n")
file.write("c DESCRIPTION: Gerado a partir das turmas de 2018.2 para TI\n")
file.write("p edge " + str(g.number_of_nodes()) +
           " " + str(g.number_of_edges())+'\n')

for line in nx.generate_edgelist(g, data=False):
    file.write("e " + line + '\n')
file.close()
