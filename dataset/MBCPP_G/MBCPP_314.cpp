int prev1 = 0, prev2 = 0, current, max_sum;
for (int i = 0; i < n; ++i) {
    max_sum = max(grid[0][i], grid[1][i]);
    current = max(prev1, prev2 + max_sum);
    prev2 = prev1;
    prev1 = current;
}
return prev1;
}