# run: main
# 	./run
main: gpio.o servidor_tcp.o cliente_tcp.o
	gcc ./src/main.c ./obj/*.o -o ./bin/run -lwiringPi
cliente_tcp.o: 
	gcc -c ./src/cliente_tcp.c -o ./obj/cliente_tcp.o
servidor_tcp.o: bme280.o
	gcc -c ./src/servidor_tcp.c -o ./obj/servidor_tcp.o
gpio.o:
	gcc -c ./src/gpio.c -o ./obj/gpio.o
bme280.o:
	gcc -c ./src/bme280.c -o ./obj/bme280.o
