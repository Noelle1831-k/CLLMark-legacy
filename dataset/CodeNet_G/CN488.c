int get_minimum_set_price(int pasta_prices[3], int juice_prices[2]) {
    int min_price = 2000 * 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            int set_price = pasta_prices[i] + juice_prices[j] - 50;
            if (set_price < min_price) {
                min_price = set_price;
            }
        }
    }
    return min_price;
}