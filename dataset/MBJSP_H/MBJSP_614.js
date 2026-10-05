function cummulativeSum(testlist) {
  let sum = 0;
  testList.forEach((item, index) => {
    sum += item.reduce((a, b) => a + b);
  });
  return sum;
}
