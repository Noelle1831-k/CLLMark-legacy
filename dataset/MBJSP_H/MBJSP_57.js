function findMaxNum(arr, n) {
    const result = arr.sort((a,b) => b - a).slice(0,n).join('')
    return parseInt(result);
}
