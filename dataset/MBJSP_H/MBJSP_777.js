function findSum(arr, n) {
    let sum = 0;
    let seen = new Set();
    for (let i = 0; i < arr.length; i++) {
        if (seen.has(arr[i])) {
            continue;
        }
        seen.add(arr[i]);
        sum += arr[i];
    }
    return sum;
}
