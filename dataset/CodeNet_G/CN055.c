double calculate_series_sum(double a) {
    double sum = 0.0;
    double current_term = a;
    for (int i = 1; i <= 10; i++) {
        sum += current_term;
        if (i % 2 == 1) {
            current_term /= 3.0;
        } else {
            current_term *= 2.0;
        }
    }
    return sum;
}