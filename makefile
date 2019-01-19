forking: client fserver

select: sclient sserver

sserver: select_server.o networking.o boardgen.o
	gcc -o server select_server.o networking.o boardgen.o

fserver: forking_server.o networking.o boardgen.o
	gcc -o server forking_server.o networking.o boardgen.o

sclient: select_client.o networking.o boardgen.o
	gcc -o client select_client.o networking.o boardgen.o

client: client.o networking.o boardgen.o
	gcc -o client client.o networking.o boardgen.o

select_client.o: select_client.c networking.h
	gcc -c select_client.c

client.o: client.c networking.h
	gcc -c client.c

select_server.o: select_server.c networking.h
	gcc -c select_server.c

forking_server.o: forking_server.c networking.h
	gcc -c forking_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

boardgen.o: boardgen.c boardgen.h
	gcc -c boardgen.c

clean:
	rm *.o
	rm *~
