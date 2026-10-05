    if (n < 1 || n > 100000000)
        return 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (2*i)*(2*i)*(2*i) ;
    }
    return sum;
}