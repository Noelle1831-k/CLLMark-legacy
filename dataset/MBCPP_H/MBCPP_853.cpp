    int sum = 0;
    for(int i = 1; i <= n; i += 2) {
        if(n % i == 0) {
            sum += i;
        }
    }
    return sum;
}