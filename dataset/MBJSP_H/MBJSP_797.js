function sumInRange(l, r) {
  let sum = 0;
  for (let i = l; i <= r; i++) {
    if (i % 2 === 1) {
      sum += i;
    }
  }
  return sum;
}
