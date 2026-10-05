int sumDigitsTwoparts(int n) {
    if (n < 10) return n; 
    int maxSum = 0;
    for (int i = 1; i <= n / 2; i++) {
        int part1 = i;
        int part2 = n - i;
        int sum1 = 0, sum2 = 0;
        int temp1 = part1, temp2 = part2;
        while (temp1 > 0) {
            sum1 += temp1 % 10;
            temp1 /= 10;
        }
        while (temp2 > 0) {
            sum2 += temp2 % 10;
            temp2 /= 10;
        }
        int totalSum = sum1 + sum2;
        if (totalSum > maxSum) {
            maxSum = totalSum;
        }
    }
    return maxSum;
}