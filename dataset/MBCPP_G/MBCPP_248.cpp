return accumulate(next(begin(vector<int>(n - 1, 1)), 1), end(vector<int>(n - 1, 1)), 1.0,
    [](double sum, int val){ return sum + 1.0 / (val + 1); });
}