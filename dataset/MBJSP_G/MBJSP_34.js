function findMissing(ar, n) {
const total = (n * (n + 1)) / 2;
  const sum = ar.reduce((acc, val) => acc + val, 0);
  return total - sum;
}
