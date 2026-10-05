void solve() {
    int N, A, B, C, Di[100], total_calories, max_calories_per_dollar = 0;
    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Di[i]);
    }
    total_calories = C;
    max_calories_per_dollar = total_calories / A;
    for (int i = 1; i < (1 << N); i++) {
        int current_calories = C;
        int toppings = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                current_calories += Di[j];
                toppings++;
            }
        }
        int price = A + toppings * B;
        int calories_per_dollar = current_calories / price;
        if (calories_per_dollar > max_calories_per_dollar) {
            max_calories_per_dollar = calories_per_dollar;
        }
    }
    printf("%d\n", max_calories_per_dollar);
}
