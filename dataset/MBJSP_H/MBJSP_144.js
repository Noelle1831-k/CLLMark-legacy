function sumPairs(arr, n) {
    var result = 0;
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (Math.abs(arr[i] - arr[j]) != 0) {
                result += Math.abs(arr[i] - arr[j]);
            }
        }
    }
    return result;
}
