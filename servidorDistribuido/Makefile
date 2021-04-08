# run: main
# 	./run
main: bme.o 
	gcc main.c ./binarios/*.o -o ./run -lwiringPi
bme.o: bme280.o
	gcc -c ./bme/bme.c -o ./binarios/bme.o
bme280.o:
	gcc -c ./bme/bme280.c -o ./binarios/bme280.o
