rm resultados.csv
echo "DSATUR;Otimo;Networkx" >> resultados.csv
for f in Test_cases/*.col
do
	./bin/graph -i $f -m >> resultados.csv
	python dsatur.py $f m >> resultados.csv
done
