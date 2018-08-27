CC=gcc
CFLAGS=-std=c99 -W -Wall -pedantic
LDFLAGS=
EXEC=mandelbrot

all: $(EXEC)

mandelbrot: main.c
	$(CC) -o mandelbrot main.c $(CFLAGS)

clean:
	rm -rf *.o mandelbrot

mrproper: clean
	rm -rf $(EXEC)
