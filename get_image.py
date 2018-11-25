import pandas as pd
import matplotlib.pyplot as plt

turmas = pd.read_csv('resultados.csv', delimiter = ';')

fig = plt.figure(figsize = (15, 5))

plt.plot(range(len(turmas["DSATUR"])), list(turmas["DSATUR"]), c = 'blue', label = 'DSATUR')
plt.plot(range(len(turmas["Otimo"])), list(turmas["Otimo"]), c = 'green', label = 'Otimo')
plt.plot(range(len(turmas["Networkx"])), list(turmas["Networkx"]), c = 'red', label = 'Networkx')
plt.xlabel('Casos de teste')
plt.ylabel('Coloracao obtida (Numero de cores)')
plt.title('Comparacao das coloracoes obtidas, as esperadas e a coloracao otima')
plt.legend(loc = 'best')
plt.savefig("Grafico")