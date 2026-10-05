function evenPosition(nums) {
return nums.every((num, index) => index % 2 !== 0 || num % 2 === 0);
}
