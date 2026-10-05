vector<long long> nsw;
    nsw.push_back(1);
    nsw.push_back(1);
    for (int i = 2; nsw.size() < n; ++i) {
        long long next_nsw = 2 * nsw[i - 1] + nsw[i - 2];
        bool isPrime = true;
        if (next_nsw < 2) isPrime = false;
        for (long long j = 2; j * j <= next_nsw; ++j) {
            if (next_nsw % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) nsw.push_back(next_nsw);
    }
    return nsw[n - 1];
}