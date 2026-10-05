function pairOrSum(arr, n) {
    let sum = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
    return sum;
}
