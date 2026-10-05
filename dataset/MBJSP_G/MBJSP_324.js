function sumOfAlternates(testtuple) {
const sum = [0, 0];
  for (let i = 0; i < testtuple.length; i++) {
    sum[i % 2] += testtuple[i];
  }
  return sum;
}
