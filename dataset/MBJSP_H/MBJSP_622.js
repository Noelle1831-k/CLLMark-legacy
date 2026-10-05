function getMedian(arr1, arr2, n) {
    const arr = arr1.concat(arr2);
    const result = [];
    arr.sort((a, b) => a - b);
    const half = Math.floor(arr.length / 2);
    if (arr1.length % n === 0) {
        result.push(arr[half]);
    }
    if (arr2.length % n === 0) {
        result.push(arr[half - 1]);
    }
    return result.reduce((a, b) => a + b) / 2;
}
