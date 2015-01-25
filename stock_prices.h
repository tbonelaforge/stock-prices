#ifndef _STOCK_PRICES_H_
#define _STOCK_PRICES_H_

struct stock_prices {
    int * prices;
    int how_many_prices;
    int state;
    int is_trending;
    int max_profit;
    int current_min;
    int current_max;
    int i; // Current position;
};

int maximize_stock_profit(struct stock_prices *);

void print_stock_prices(struct stock_prices *);

#endif
