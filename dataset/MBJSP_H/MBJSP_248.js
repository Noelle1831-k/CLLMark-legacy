function harmonicSum(n) {
  let sum = 0;
  for (let i = 0; i < n; i++) {
    sum += 1.0 / (i + 1);
  }
  return sum;
}
