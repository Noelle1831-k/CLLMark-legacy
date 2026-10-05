    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp) {
            if (temp % 2 == 0) {
                cnt += 1;
            }
            temp /= 2;
        }
    }
    return cnt;
}