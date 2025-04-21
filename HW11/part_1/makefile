CC = gcc
CFLAGS = -Wall -Wextra -std=c11
CFLAGS = -Wall -Wextra -std=c11 -fexec-charset=CP1251

all: temp_app

temp_app: main.o temp_api.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

clean:
	rm -f *.o temp_app