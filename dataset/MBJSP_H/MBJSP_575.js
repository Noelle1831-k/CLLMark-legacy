function countNo(a, n, l, r) {
  let count = 0;
  for (let i = l; i <= r; i++) {
    if (i % a !== 0) {
      count++;
    }
    if (count === n) {
      return i;
    }
  }
  return -1;
}
