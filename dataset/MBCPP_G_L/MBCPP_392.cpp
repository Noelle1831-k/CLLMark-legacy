if (n <= 0) return 0;
unordered_map<int, int> dp;
function<int(int)> compute = [&](int x) {
    if (x <= 0) return 0;
    if (dp.find(x) != dp.end()) return dp[x];
    return dp[x] = max(x, compute(x / 2) + compute(x / 3) + compute(x / 4) + compute(x / 5));
};
return compute(n);
}