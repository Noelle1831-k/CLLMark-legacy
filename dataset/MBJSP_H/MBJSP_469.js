function maxProfit(price, k) {
    let maxProfit = 0;
    for (let i = 0; i < k; i++) {
        let profit = 0;
        for (let j = 0; j < price.length; j++) {
            if (price[j] < price[j + 1]) {
                profit += price[j + 1] - price[j];
            }
        }
        maxProfit = Math.max(profit, maxProfit);
    }
    return maxProfit;
}
