CC = gcc
CFLAGS = -lGL -lGLU -lglut -lm
TARGET = super_bart.o

all: bart.o
	$(CC) -o $(TARGET) bart.o $(CFLAGS)

bart.o: bart.c
	$(CC) -c bart.c $(CFLAGS)

clean:
	$(RM) *.o
