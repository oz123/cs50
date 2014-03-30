CC=clang
CFLAGS=-ggdb3 -O0 -std=c99 -O3 -Wall -Werror

# run with $ DEBUG=1 make 
# this will add debug symbols to the binary
ifdef DEBUG
  CFLAGS+=-g
endif 

LIBS=-lcs50 -lm

# use this when compiling with -static

	# $@ - left side of :
	# $^ - right side of :
	# $< is the first item in the dependencies list


all: build run

build:
	$(CC) AllTests.c CuTest.c TestCeasar.c $^ $(CFLAGS) $(LIBS) \
		-o test_runner

run:
	./test_runner

clean:
	$(RM) test_runner
