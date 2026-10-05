function maxLenSub(arr, n) {
    var mls = new Array(n);
    var max = 0;
    for (var i = 0; i < n; i++) {
        mls[i] = 1;
    }
    for (var i = 0; i < n; i++) {
        for (var j = i - 1; j >= 0; j--) {
            if (arr[i] - arr[j] <= 1 && mls[i] < mls[j] + 1) {
                mls[i] = mls[j] + 1;
            }
        }
    }
    for (var i = 0; i < n; i++) {
        if (max < mls[i]) {
            max = mls[i];
        }
    }
    return max;
}
