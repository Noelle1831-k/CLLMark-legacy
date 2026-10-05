function consecutiveDuplicates(nums) {
    let newArr = [];
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === nums[i + 1]) {
            continue;
        }
        newArr.push(nums[i]);
    }
    return newArr;
}
