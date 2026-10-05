function isSubsetSum(set, n, sum) {
    var s = sum;
    var n_1 = [];
    var sum_1 = 0;
    for (var i = 0; i < n; i++) {
        n_1.push(i);
    }
    for (var i = 0; i < n; i++) {
        sum_1 += n_1[i];
    }
    for (var i = 0; i < n; i++) {
        if (s > sum_1) {
            return false;
        }
        s -= n_1[i];
    }
    return true;
}
