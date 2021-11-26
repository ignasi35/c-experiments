all:
	gcc hello.c -o hello.runnable

clean:
	rm -f hello.runnable

run: all
	./hello.runnable
