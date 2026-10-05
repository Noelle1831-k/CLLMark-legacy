function bigDiff(nums) {
    let max = nums[0],
        smallest = nums[nums.length - 1];
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > max) {
            max = nums[i];
        } else if (nums[i] < smallest) {
            smallest = nums[i];
        }
    }
    return max - smallest;
}
