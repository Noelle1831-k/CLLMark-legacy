function getMaxSum(n) {
    if (n === 0) {
        return 0;
    } else if (n === 1) {
        return 1;
    } else {
        return Math.max((getMaxSum(Math.floor(n/2)) + getMaxSum(Math.floor(n/3)) + getMaxSum(Math.floor(n/4)) + getMaxSum(Math.floor(n/5)) ), n);
    }
}
