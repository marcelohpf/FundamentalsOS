CC=gcc
FLAGS=-lm -o
FILES=main.c
OUT_FILE=arguments.out

make:
	${CC} ${FILES} ${FLAGS} ${OUT_FILE}

run:
	./${OUT_FILE}

clean:
	clear
	rm -f *.out

teste:
	./${OUT_FILE} -a coisas -b 10 20 30 40 -1 -c /home/
