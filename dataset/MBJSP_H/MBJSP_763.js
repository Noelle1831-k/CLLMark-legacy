function findMinDiff(arr, n) {
    let minDiff = Infinity;
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            let diff = Math.abs(arr[i] - arr[j])
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
    }
    return minDiff
}
