function sumOfPrimes(n) {
  let sum = 0;
  let primeNumbers = 2;

  let primes = [];

  let checkSum = (a, b) => {
    for (let i = 2; i < b; i++) {
      if (a % i === 0) {
        return false;
      }
    }
    return true;
  }

  for (let i = 2; i <= n; i++) {
    if (primes.length === primeNumbers) {
      primes.push(i);
    }
    if (checkSum(i, primes.length)) {
      sum += i;
    }
    primes.push(i);
  }

  return sum;
}
