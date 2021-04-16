# run: main
# 	./run
main: gpio.o servidor_tcp.o
	gcc main.c ./binarios/*.o -o ./run -lwiringPi
servidor_tcp.o: bme280.o
	gcc -c ./servidorTcp/servidor_tcp.c -o ./binarios/servidor_tcp.o
gpio.o:
	gcc -c ./gpio/gpio.c -o ./binarios/gpio.o
bme280.o:
	gcc -c ./bme/bme280.c -o ./binarios/bme280.o
