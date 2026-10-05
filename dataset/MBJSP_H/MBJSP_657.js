function firstDigit(n) {
  let count = 1;
  for (let i = 1; i <= n; i++) {
    count *= i;
  }
  return parseInt(count.toString().charAt(0));
}
