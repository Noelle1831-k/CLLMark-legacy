function firstMissingPositive(arr, n) {
    let i = 0;
    let result = 1;
    while (result <= n) {
        if (arr.indexOf(result) === -1) {
            return result;
        }
        result += 1;
    }
    return result - 1;
}
