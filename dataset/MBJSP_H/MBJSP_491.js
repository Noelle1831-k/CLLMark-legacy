function sumGp(a, n, r) {
    let sum = 0;
    for (let i = 1; i <= n; i++) {
        sum += a * Math.pow(r, i - 1)
    }
    return sum;
}
