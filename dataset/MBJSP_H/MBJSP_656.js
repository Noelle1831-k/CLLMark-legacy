function findMinSum(a, b, n) {
  let firstArray = a.concat();
  let secondArray = b.concat();

  firstArray.sort((a, b) => a - b);
  secondArray.sort((a, b) => a - b);

  let firstSum = 0;
  let secondSum = 0;

  for (let i = 0; i < n; i++) {
    firstSum += Math.abs(firstArray[i] - secondArray[i]);
  }

  return firstSum - secondSum;
}
