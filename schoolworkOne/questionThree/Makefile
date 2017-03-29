CC=gcc
FLAGS=-lm -o
FILES=main.c sort.c io.c
OUT_FILE=sort.out

make:
	${CC} ${FILES} ${FLAGS} ${OUT_FILE}

run:
	./${OUT_FILE}

clean:
	clear
	rm -f *.out
test-increscent:
	./${OUT_FILE} -d < input.txt

test-decrease:
	./${OUT_FILE} -r < input.txt

test-default:		
	./${OUT_FILE} < input.txt
