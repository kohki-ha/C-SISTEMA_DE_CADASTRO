main: main.o
	@echo "Gerando arquivo executavel"
	gcc *.c -o main

main.o: main.c
	@echo "Compilando e gerando o objeto main"
	gcc -c *.c

clean:
	rm -f *.o main

run:
	./main
