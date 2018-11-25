for f in Test_cases/*.col
do
	./bin/graph $f >> resultados.txt
	python DSATUR.py $f >> resultados.txt
done
