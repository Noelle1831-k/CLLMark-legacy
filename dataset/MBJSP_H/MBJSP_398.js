function sumOfDigits(nums) {
    return nums.reduce((total, num) => {
        return total + (num.toString().match(/(\d)/g) || []).reduce((t, n) => {
            return t + +n;
        }, 0);
    }, 0);
}
