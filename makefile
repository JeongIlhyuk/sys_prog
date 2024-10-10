CC=gcc
CFLAGS=-O3
OBJECTS=makeEx.o
TARGET=func
$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJECTS):makeEx.c
	${CC} ${CFLAGS} -c makeEx.c
clean:
	rm *.o ${TARGET}
