function sumEvenAndEvenIndex(arr, n) {
    var result = 0;
    for (let i = 0; i < n; i += 2) {
        if (arr[i] % 2 == 0) {
            result += arr[i];
        }
    }
    return result;
}
