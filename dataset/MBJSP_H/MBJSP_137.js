function zeroCount(nums) {
    const zeros = nums.filter((x) => x === 0).length;
    return Math.round(zeros / nums.length * 100) / 100;
}
