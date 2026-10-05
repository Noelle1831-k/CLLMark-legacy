function harmonicSum(n) {
    let total = 0;
    for (let i = 1; i <= n; i++) {
        total += 1 / i;
    }
    return total;
}
