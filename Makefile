# Makefile

include config.mk

CC=gcc
CFLAGS=-W -Wall -Wextra -pedantic -ansi
LDFLAGS=
EXEC=kbacklight

all: $(EXEC)

kbacklight: main.o version.o errors.o setup.o brightness.o
	$(CC) -o kbacklight main.o version.o errors.o setup.o brightness.o $(LDFLAGS)

main.o: main.c config.h errors.h setup.h brightness.h
	$(CC) -o main.o -c main.c $(CFLAGS)

version.o: version.c version.h
	$(CC) -o version.o -c version.c $(CFLAGS)

errors.o: errors.c errors.h
	$(CC) -o errors.o -c errors.c $(CFLAGS)

setup.o: setup.c setup.h version.h
	$(CC) -o setup.o -c setup.c $(CFLAGS)

brightness.o: brightness.c brightness.h config.h errors.h
	$(CC) -o brightness.o -c brightness.c $(CFLAGS)

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f kbacklight ${DESTDIR}${PREFIX}/bin
	chown root:root ${DESTDIR}${PREFIX}/bin/kbacklight
	chmod 4755 ${DESTDIR}${PREFIX}/bin/kbacklight

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/kbacklight

clean:
	rm -rf *.o

