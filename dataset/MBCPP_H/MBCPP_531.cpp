    if (v == 0) {
        return 0;
    }
    if (v < 0) {
        return -1;
    }
    int min = -1;
    for (int c : coins) {
        int result = minCoins(coins, m, v - c);
        if (result != -1 && (min == -1 || result < min)) {
            min = result;
        }
    }
    return min + 1;
}