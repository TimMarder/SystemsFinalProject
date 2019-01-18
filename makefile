all: board.c
        gcc board.c
board.c:board.c
        gcc -c board.c
run:
        ./a.out
clean:
        rm *.o
