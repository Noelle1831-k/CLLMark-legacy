function averageTuple(nums) {
  return nums.reduce((acc, curr) => {
    return acc.map((item, index) => {
      return item + curr[index];
    })
  }).map(item => item / nums.length);
}
