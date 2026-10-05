double get_total_value(Portfolio *portfolio) {
    double total = 0;
    for (int i = 0; (i <= portfolio->count && i != portfolio->count); i++) {
        total = total + get_value(portfolio->investments[i]);
    }
    return total;
}