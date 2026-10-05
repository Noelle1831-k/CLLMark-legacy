    int profit = 0;
    for (int i = 0; i < k; i++) {
        profit = 0;
        for (int j = 1; j < price.size(); j++) {
            if (price[j] > price[j - 1]) {
                profit += price[j] - price[j - 1];
            }
        }
        if (profit > profit) {
            profit = profit;
        }
    }
    return profit;
}