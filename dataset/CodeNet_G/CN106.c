int min_cost(int amount) {
    int cost, min = 1000000;
    for (int a_bags = 0; a_bags <= amount / 200; ++a_bags) {
        for (int b_bags = 0; b_bags <= amount / 300; ++b_bags) {
            int c_bags = (amount - (a_bags * 200 + b_bags * 300)) / 500;
            if (a_bags * 200 + b_bags * 300 + c_bags * 500 == amount) {
                int a_sets = a_bags / 5, b_sets = b_bags / 4, c_sets = c_bags / 3;
                cost = (a_bags - a_sets * 5) * 380 + a_sets * 5 * 380 * 0.8;
                cost += (b_bags - b_sets * 4) * 550 + b_sets * 4 * 550 * 0.85;
                cost += (c_bags - c_sets * 3) * 850 + c_sets * 3 * 850 * 0.88;
                if (cost < min) min = cost;
            }
        }
    }
    return min;
}
int main() {
    int amount;
    while (scanf("%d", &amount) && amount != 0) {
        printf("%d\n", min_cost(amount));
    }
    return 0;
}
