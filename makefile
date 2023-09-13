BIN = hxx
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
LDLIBS =
LDFLAGS = -fuse-ld=lld

.SUFFIXES: .c .o

${OBJ}: hxx.c
	${CC} ${CFLAGS} -c $< ${LDLIBS}

${BIN}: hxx.o
	${CC} ${LDFLAGS} -o $@ hxx.o ${LDLIBS}

clean:
	rm -rf *.o ${BIN}

.PHONY: clean
