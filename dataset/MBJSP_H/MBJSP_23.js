function maximumSum(list1) {
  let maxSum = 0;
  let maxIndex = 0;
  const length1 = list1.length;

  while (maxIndex < length1) {
    let sum = 0;
    for (let i = 0; i < list1[maxIndex].length; i++) {
      sum += list1[maxIndex][i];
    }
    maxSum = Math.max(maxSum, sum);
    maxIndex ++;
  }
  return maxSum;
}
