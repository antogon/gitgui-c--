default: all
all:
	g++ -o main *.cpp `pkg-config --libs --cflags gtk+-3.0`

clean:
	rm -rf main
