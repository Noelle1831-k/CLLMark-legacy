function fifthPowerSum(n) {
  let result = 0;
  for (let i = 1; i <= n; i++) {
    result = result + Math.pow(i, 5);
  }
  return result;
}
