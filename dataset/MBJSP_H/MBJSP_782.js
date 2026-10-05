function oddLengthSum(arr) {
    var Sum = 0;
    var l = arr.length;
    for (var i = 0; i < l; i++) {
        Sum += ((((i + 1) * (l - i) + 1) >> 1) * arr[i]);
    }
    return Sum;
}
