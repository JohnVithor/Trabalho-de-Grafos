for f in Test_cases/*.col
do
	./bin/graph $f >> resultados.txt
done
