rm resultados.csv
echo "Tamanho;Tempo DSATUR;DSATUR;Otimo;Networkx;tempo Networkx" >> resultados.csv
for f in Test_cases/*.col
do
	./bin/DSATUR -i $f -m >> resultados.csv
	./dsatur.py $f m >> resultados.csv
done
