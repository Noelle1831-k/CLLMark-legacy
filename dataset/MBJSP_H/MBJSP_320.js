function sumDifference(n) {
  let sum1 = 0;
  let sum2 = 0;

  for (let i = 1; i <= n; i++) {
    sum1 += i;
    sum2 += Math.pow(i, 2);
  }

  return Math.pow(sum1, 2) - sum2;
}
