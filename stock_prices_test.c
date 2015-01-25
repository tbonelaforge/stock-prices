#include <stdio.h>

#include "stock_prices.h"

int main() {
    printf("About to test the stock prices: [2, 3]\n");
    int test_prices[] = {
        2,
        3
    };
    struct stock_prices test_stocks;
    test_stocks.prices = test_prices;
    test_stocks.how_many_prices = 2;

    printf("The newly-constructed stock prices looks like:\n");
    print_stock_prices(&test_stocks);
    printf("About to maximize profit...\n");
    int result = maximize_stock_profit(&test_stocks);
    printf("The maximum profit is: %d\n", result);

    int test_prices2[] = {
        3,
        2,
        1
    };
    struct stock_prices stock_prices2;
    stock_prices2.prices = test_prices2;
    stock_prices2.how_many_prices = 3;

    printf("Considering the stock prices:\n");
    print_stock_prices(&stock_prices2);
    result = maximize_stock_profit(&stock_prices2);
    printf("The maximum profit for those is: %d\n", result);

    
    int test_prices3[] = {
        3,
        -2,
        5,
        6,
        7,
        10,
        9,
        2,
        1,
        0,
        1,
        0,
        5
    };
    struct stock_prices test_stock_prices3;
    test_stock_prices3.prices = test_prices3;
    test_stock_prices3.how_many_prices = 13;
    printf("The big test looks like: \n");
    print_stock_prices(&test_stock_prices3);
    result = maximize_stock_profit(&test_stock_prices3);
    printf("The maximum profit for the big test is: %d\n", result);
}
