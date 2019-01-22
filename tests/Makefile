CC=g++
LD=g++

CFLAGS=-Wall -Wextra -I../include

all: BotTest


BotTest: testmain.o test_rapidjson.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(RM) -f *.o BotTest
