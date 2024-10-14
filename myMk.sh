CFLAGS=-O3
CC=gcc
OBJECTS=main.o func.o
TARGET=func

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
func.o: func.c
	$(CC) $(CFLAGS) -c func.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
clean:
	rm $(OBJECTS) $(TARGET)
