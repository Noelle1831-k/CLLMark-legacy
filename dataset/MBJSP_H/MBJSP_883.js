function divOfNums(nums, m, n) {
    return nums.filter((item) => {
        return item % m === 0 && item % n === 0;
    });
}
