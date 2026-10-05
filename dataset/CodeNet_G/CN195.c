void process_sales() {
    int s1A, s2A, s1B, s2B, s1C, s2C, s1D, s2D, s1E, s2E;
    while (1) {
        scanf("%d %d %d %d %d %d %d %d %d %d", &s1A, &s2A, &s1B, &s2B, &s1C, &s2C, &s1D, &s2D, &s1E, &s2E);
        if (s1A == 0 && s2A == 0) break;
        int totalA = s1A + s2A;
        int totalB = s1B + s2B;
        int totalC = s1C + s2C;
        int totalD = s1D + s2D;
        int totalE = s1E + s2E;
        char max_store;
        int max_sales;
        max_sales = totalA;
        max_store = 'A';
        if (totalB > max_sales) {
            max_sales = totalB;
            max_store = 'B';
        }
        if (totalC > max_sales) {
            max_sales = totalC;
            max_store = 'C';
        }
        if (totalD > max_sales) {
            max_sales = totalD;
            max_store = 'D';
        }
        if (totalE > max_sales) {
            max_sales = totalE;
            max_store = 'E';
        }
        printf("%c %d\n", max_store, max_sales);
    }
}