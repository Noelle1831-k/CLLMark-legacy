int min_price(int A, int B, int X) {
    int min_cost = 1000000;
    int liters, half_liters, needed_01, cost;
    for (liters = 0; liters <= (X + 999) / 1000; liters++) {
        needed_01 = X - liters * 1000;
        half_liters = (needed_01 > 0) ? (needed_01 + 499) / 500 : 0;
        cost = liters * A + half_liters * B;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}