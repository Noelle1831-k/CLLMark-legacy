function sumDifference(n) {
const sumOfSquares = (n * (n + 1) * (2 * n + 1)) / 6;
  const squareOfSum = Math.pow((n * (n + 1)) / 2, 2);
  return squareOfSum - sumOfSquares;
}
