CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm
TARGET = temp_analyzer
SRC = main.c temp_api.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean