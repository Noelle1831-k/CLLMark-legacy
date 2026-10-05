int calculate_score(int cards[], int n) {
    int sum = 0, aces = 0;
    for (int i = 0; i < n; i++) {
        if (cards[i] == 1) {
            aces++;
            sum += 1;
        } else if (cards[i] >= 10) {
            sum += 10;
        } else {
            sum += cards[i];
        }
    }
    while (aces > 0 && sum <= 11) {
        sum += 10;
        aces--;
    }
    return sum > 21 ? 0 : sum;
}