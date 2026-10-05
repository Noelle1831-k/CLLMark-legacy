long long result = 1;
    for (int i = 0; i < power; ++i) {
        result *= base;
    }
    int sum = 0;
    while (result > 0) {
        sum += result % 10;
        result /= 10;
    }
    return sum;
}