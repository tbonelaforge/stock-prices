#include <stdio.h>
#include <stdlib.h>

#include "stock_prices.h"

int INCREASING = 1;
int DECREASING = -1;

int maximize_stock_profit(struct stock_prices *);
int next_extremum(struct stock_prices *);
int get_local_max(struct stock_prices *);
int get_local_min(struct stock_prices *);
void record_extremum(struct stock_prices *);
void record_local_min(struct stock_prices *);
void record_local_max(struct stock_prices *);
void toggle_state(struct stock_prices *);

int debug = 0;

int maximize_stock_profit(struct stock_prices * self) {
    if (self->how_many_prices < 2) {
        return -1;
    }
    self->max_profit = -1;  // Means no good buy/sell times.
    self->i = -1;
    self->state = DECREASING;
    self->is_trending = 0;
    while (next_extremum(self) > -1 ) {
        record_extremum(self);
        toggle_state(self);
    }
    return self->max_profit;
}

int next_extremum(struct stock_prices * self) {
    if (self->i >= self->how_many_prices - 1) {
        return -1;
    }
    self->i += 1;
    if (self->state == INCREASING) {
        return get_local_max(self);
    } else { // state is DECREASING
        return get_local_min(self);
    }
}

int get_local_max(struct stock_prices * self) {
    while (self->i + 1 < self->how_many_prices &&
           self->prices[self->i + 1] >= self->prices[self->i]) {
        self->i += 1;
    }
    return self->i;
}

int get_local_min(struct stock_prices * self) {
    while (self->i + 1 < self->how_many_prices &&
           self->prices[self->i + 1] <= self->prices[self->i]) {
        self->i += 1;
    }
    return self->i;
}

void record_extremum(struct stock_prices * self) {
    if (self->state == INCREASING) {
        record_local_max(self);
    } else { // state is DECREASING
        record_local_min(self);
    }
}

void record_local_max(struct stock_prices * self) {
    int this_price = self->prices[self->i];

    if (!self->is_trending || 
        this_price > self->current_max) {
        self->current_max = this_price;
        self->is_trending = 1;
        self->max_profit = self->current_max - self->current_min;
    }
}

void record_local_min(struct stock_prices * self) {
    int this_price = self->prices[self->i];

    if (this_price < self->current_min || self->max_profit == -1) {
        self->current_min = this_price;
        self->is_trending = 0;
    }
}

void print_stock_prices(struct stock_prices * self) {
    int i;

    printf("prices: [");
    for (i = 0; i < self->how_many_prices; i++) {
        printf("%d", self->prices[i]);
        if (i < self->how_many_prices - 1) {
            printf(", ");
        }
    }
    printf("]");
    printf("\nState: %d\nIs Trending: %d\nMax Profit: %d", self->state, self->is_trending, self->max_profit);
    printf("\nCurrent Min: %d\nCurrent Max: %dCurrent Position: %d\n", self->current_min, self->current_max, self->i);
}

void toggle_state(struct stock_prices * self) {
    self->state *= -1;
}
