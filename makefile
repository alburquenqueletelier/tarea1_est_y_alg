all: main.c
	gcc -o main main.c

clean_txt:
	rm -f *.txt

clean:
	rm -f main *.txt