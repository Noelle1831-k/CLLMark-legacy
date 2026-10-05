function minOps(arr, n, k) {
    if (arr == null || arr.length == 0 || n <= 0 || k <= 0) {
        return -1;
    }

    var max1 = arr[arr.length - 1];
    var res = 0;
    for (var i = 0; i < n; i++) {
        if ((max1 - arr[i]) % k != 0) {
            return -1;
        } else {
            res += (max1 - arr[i]) / k;
        }
    }
    return res;
}
