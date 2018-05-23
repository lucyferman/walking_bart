CC = gcc
CFLAGS = -lGL -lGLU -lglut -lm
TARGET = super_bart.o

all: bart.o body.o body_utils.o
	$(CC) -o $(TARGET) bart.o body.o body_utils.o $(CFLAGS)

body_utils.o: body_utils.c body_utils.h
	$(CC) -c body_utils.c

body.o: body.c body.h body_utils.h
	$(CC) -c body.c

bart.o: bart.c body.h
	$(CC) -c bart.c $(CFLAGS)

clean:
	$(RM) *.o
