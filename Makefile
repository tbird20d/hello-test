all: hello

VERSION=1.1
TARFILE=hello-test-${VERSION}.tgz

hello: hello.c
	${CC} $< -o $@

clean:
	rm -f hello

test:
	@./hello -r

distclean: clean
	rm -f ../${TARFILE} ../hello-test-${VERSION}

dist: clean
	ln -sf hello-test ../hello-test-${VERSION}
	tar -h -czvf ../${TARFILE} -C .. --exclude=*/.git* hello-test-${VERSION}/
