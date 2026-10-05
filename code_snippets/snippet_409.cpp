    int profit = 0;
    int buy = price[0];
    if (k == 1) {
        for (int i = 1; i < price.size(); i++) {
            if (price[i] > buy) {
                profit += price[i] - buy;
            }
            buy = price[i];
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < price.size(); j++) {
                if (price[j] > buy) {
                    profit += price[j] - buy;
                }
                buy = price[j];
            }
        }
    }
    return profit;
}
<|endoftext|>