function sumOfSubarrayProd(arr, n) {
    let sum = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            let product = arr.slice(i, j + 1).reduce((a, b) => a * b);
            sum += product;
        }
    }
    return sum;
}
