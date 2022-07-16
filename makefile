main: main.o
	@echo "Generating executable file..."
	gcc *.o -o main
	del /Q /F *.o
	@echo "Executable file generated!"

main.o: main.c
	@echo "Compiling and generating object..."
	gcc -c ./src/*.c
	gcc -c *.c
	@echo "Objects generated!"

clean:
	@echo "Cleaning project's exe & objects files..."
# for linux: 
#	rm -f main.exe *.o main
# for windows: 
	del /Q /F main.exe *.o
	@echo "Cleaning completed!"

run:
	./main