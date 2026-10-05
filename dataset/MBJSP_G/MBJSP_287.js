function squareSum(n) {
let sum = 0;
  for (let i = 1; i <= n; i++) {
    sum += Math.pow(2 * i, 2);
  }
  return sum;
}
