function positiveCount(nums) {
    let result = nums.filter(num => num > 0).length / nums.length;
    return Math.round(result * 100) / 100;
}
