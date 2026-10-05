function maxSubArraySum(a, size) {
    let result = 0;
    let maxSum = 0;
    for (let i = 0; i < size; i++) {
        let sum = 0;
        for (let j = i; j < a.length; j++) {
            sum += a[j];
            if (sum > maxSum) {
                maxSum = sum;
                result = j - i + 1;
            }
        }
    }
    return result;
}
