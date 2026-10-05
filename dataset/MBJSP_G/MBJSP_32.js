function maxPrimeFactors(n) {
let maxPrime = 2;
  while (n % 2 === 0) {
    n = n / 2;
  }
  for (let i = 3; i * i <= n; i += 2) {
    while (n % i === 0) {
      maxPrime = i;
      n = n / i;
    }
  }
  if (n > 2) {
    maxPrime = n;
  }
  return maxPrime;
}
