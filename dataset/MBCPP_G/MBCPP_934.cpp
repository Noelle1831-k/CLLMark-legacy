if (n == 0 || m == 0) return 1;
    return dealnnoyNum(n - 1, m) + dealnnoyNum(n - 1, m - 1) + dealnnoyNum(n, m - 1);
}