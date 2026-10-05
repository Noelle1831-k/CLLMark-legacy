    int s = 0;
    for (int i = 2; i <= limit; ++i) {
        int sumFactor = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0)
                sumFactor += j;
        }
        int sumFactorSum = 0;
        for (int j = 1; j < sumFactor; j++) {
            if (sumFactor % j == 0)
                sumFactorSum += j;
        }
        if (i == sumFactorSum && i != sumFactor && sumFactor != 0)
            s += i;
    }
    return s;
}