int sequence(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int newman_conway[n+1];
    newman_conway[1] = 1;
    newman_conway[2] = 1;
    for (int i = 3; i <= n; i++) {
        newman_conway[i] = newman_conway[newman_conway[i - 1]] + newman_conway[i - newman_conway[i - 1]];
    }
    return newman_conway[n];
}