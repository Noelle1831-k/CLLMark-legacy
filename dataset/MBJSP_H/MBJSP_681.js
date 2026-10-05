function smallestDivisor(n) {
  if (n < 10) {
    return n;
  }

  for (let i = 2; i < n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
