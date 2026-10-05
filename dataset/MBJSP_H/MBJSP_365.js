function countDigit(n) {
  const digits = [];
  while (n > 1) {
    digits.push(n % 10);
    n /= 10;
  }
  return digits.length;
}
