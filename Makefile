all: hello

hello: hello.c
	gcc $< -o $@

clean:
	rm hello

test:
	@./hello | grep status
