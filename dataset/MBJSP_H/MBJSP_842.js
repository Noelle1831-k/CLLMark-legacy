function getOddOccurence(arr, arrsize) {
    var o = 0;
    for (let i = 0; i < arrSize; i++) {
        o ^= arr[i];
    }
    return o;
}
