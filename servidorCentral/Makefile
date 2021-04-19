main: cliente_tcp.o servidor_tcp.o arquivo.o
	gcc ./src/main.c ./obj/*.o -o ./bin/run -lpthread
servidor_tcp.o:
	gcc -c ./src/servidor_tcp.c -o ./obj/servidor_tcp.o 
cliente_tcp.o:
	gcc -c ./src/cliente_tcp.c -o ./obj/cliente_tcp.o
arquivo.o:
	gcc -c ./src/arquivo.c -o ./obj/arquivo.o 