function sumOfProduct(n) {
    if (n === 0) return 1;
    let product = 1;
    for (let i = 0; i <= n; i++) {
        product = product * (n + i) / (i + 1);
    }
    return product;
}
