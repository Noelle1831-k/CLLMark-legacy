int calculate_min_cost(int x, int y, int b, int p) {
    int totalCostWithoutDiscount = b * x + p * y;
    int totalCostWithDiscount = b * x + p * y;
    if (b >= 5 && p >= 2) {
        totalCostWithDiscount = (b * x + p * y) * 8 / 10;
    } else {
        if (b < 5) {
            totalCostWithDiscount = (5 * x + p * y) * 8 / 10;
        } else {
            totalCostWithDiscount = (b * x + 2 * y) * 8 / 10;
        }
    }
    if (b < 5 && p < 2) {
        totalCostWithDiscount = totalCostWithoutDiscount;
    }
    return totalCostWithDiscount < totalCostWithoutDiscount ? totalCostWithDiscount : totalCostWithoutDiscount;
}