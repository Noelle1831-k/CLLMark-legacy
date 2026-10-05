function twoUniqueNums(nums) {
    return nums.filter(item => {
        var i = nums.indexOf(item);
        return i == nums.lastIndexOf(item);
    });
}
