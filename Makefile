all: stock_prices_test.bin

stock_prices_test.bin: stock_prices_test.c stock_prices.h stock_prices.o
	gcc -I ./ stock_prices_test.c stock_prices.o -o stock_prices_test.bin

stock_prices.o: stock_prices.h stock_prices.c
	gcc -I ./ -c stock_prices.c
