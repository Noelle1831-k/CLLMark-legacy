function maxSubArraySumRepeated(a, n, k) {
    let currentSum = 0;
    let currentMaxSum = -1;
    let currentMaxPos = -1;
    let currentMaxPosIndex = -1;
    for (let i = 0; i < k; i++) {
        for (let j = i; j < a.length; j++) {
            if (a[j] + currentSum > currentMaxSum) {
                currentMaxSum = a[j] + currentSum;
                currentMaxPos = j;
                currentMaxPosIndex = i;
            }
            currentSum += a[j];
        }
    }
    return currentMaxSum > currentMaxSum ? -1 : currentMaxSum;
}
