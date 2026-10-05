int findWaysUtil(int pos, int sum, int m) {
    if (pos == m) {
        return sum >= 0 ? 1 : 0;
    }
    int ways = 0;
    ways += findWaysUtil(pos + 1, sum + 1, m);
    ways += findWaysUtil(pos + 1, sum - 1, m);
    return ways;
}
int findWays(int m) {
    return findWaysUtil(0, 1, m);
}