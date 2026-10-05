int calculate_coins(int payment) {
    int change = 1000 - payment;
    int coins = 0;
    int denominations[] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; i++) {
        coins += change / denominations[i];
        change %= denominations[i];
    }
    return coins;
}