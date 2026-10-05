int calculate_max_bags(int n, int weights[]) {
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        if (weights[i] >= 1 && weights[i] <= 9) {
            count[weights[i]]++;
        }
    }
    int max_bags = 0;
    while (1) {
        int sum = 0;
        for (int i = 9; i >= 1; i--) {
            while (count[i] > 0 && sum + i <= 10) {
                sum += i;
                count[i]--;
            }
        }
        if (sum == 10) {
            max_bags++;
        } else {
            break;
        }
    }
    return max_bags;
}