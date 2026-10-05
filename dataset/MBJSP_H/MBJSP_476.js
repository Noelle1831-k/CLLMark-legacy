function bigSum(nums) {
    // if (nums.length < 2) {
    //     return nums;
    // }
    let sum = nums.reduce((sum, curr) => {
        return sum + curr;
    }, 0);

    return nums[nums.length - 1] + nums[0];
}
