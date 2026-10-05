function maxOccurrences(nums) {
    let obj = {};
    let currentMax = -Infinity;
    let result = [];
    for (let i = 0; i < nums.length; i++) {
        if (obj[nums[i]] === undefined) {
            obj[nums[i]] = 1;
        } else {
            obj[nums[i]] = obj[nums[i]] + 1;
        }
        if (obj[nums[i]] > currentMax) {
            currentMax = obj[nums[i]];
            result = [nums[i]];
        } else if (obj[nums[i]] === currentMax) {
            result.push(nums[i]);
        }
    }
    return result.length > 1 ? result : result[0];
}
