CC = gcc
CFLAGS = -lGL -lGLU -lglut -lm
TARGET = super_bart.o

all: bart.o body.o
	$(CC) -o $(TARGET) bart.o body.o $(CFLAGS)

body.o: body.c body.h
		$(CC) -c body.c

bart.o: bart.c body.h
	$(CC) -c bart.c $(CFLAGS)

clean:
	$(RM) *.o
