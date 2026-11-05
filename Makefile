CC = gcc
CFLAGS = -Iinclude
EXEC = calculatrice

all: $(EXEC)

$(EXEC): main.o conversion.o
	$(CC) main.o conversion.o -o $(EXEC)

main.o: src/main.c include/conversion.h
	$(CC) $(CFLAGS) -c src/main.c -o main.o

conversion.o: src/conversion.c include/conversion.h
	$(CC) $(CFLAGS) -c src/conversion.c -o conversion.o

clean:
	del /f /q *.o $(EXEC).exe