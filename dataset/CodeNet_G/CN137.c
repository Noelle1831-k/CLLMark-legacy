void generate_squares(int s, int n, int dataset_number) {
    int current = s;
    printf("Case %d:", dataset_number);
    for (int i = 0; i < 10; i++) {
        int square = current * current;
        char square_str[9];
        snprintf(square_str, sizeof(square_str), "%08d", square);
        char middle[n + 1];
        strncpy(middle, square_str + (8 - n) / 2, n);
        middle[n] = '\0';
        current = atoi(middle);
        printf(" %d", current);
    }
    printf("\n");
}