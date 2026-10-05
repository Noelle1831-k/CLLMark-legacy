function sumOfOddFactors(n) {
    let f = [];
    for (let i = 1; i <= n; i++) {
        if (n % i === 0) {
            f.push(i);
        }
    }
    f = f.filter((item) => item % 2 === 1);
    return f.reduce((sum, item) => sum + item, 0);
}
