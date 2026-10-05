int i = 0, count = 0;
while (count < n) {
    i++;
    int val = 1, sum = 0;
    for (int j = 2; sum <= i && j < i; j++) {
        if (i % j == 0) {
            sum += val;
        }
        val++;
    }
    if (sum == i - 1) count++;
}
return i;
}