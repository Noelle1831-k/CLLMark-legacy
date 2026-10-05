function countFac(n) {
  let count = 0;

  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (n % i === 0) {
      count ++;
    }
  }
  return count;
}
