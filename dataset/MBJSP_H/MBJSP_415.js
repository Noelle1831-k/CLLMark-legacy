function maxProduct(arr) {
    let maxProduct = [1, 1];
    let temp;
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            if (i !== j) {
                if (arr[i] * arr[j] > maxProduct[0] * maxProduct[1]) {
                    maxProduct = [arr[i], arr[j]];
                }
            }
        }
    }
    return maxProduct;
}
