function countNum(n) {
  for (let i = 2; i < n; i++) {
    if ((i % 2) == 0) {
      return i;
    }
  }
  return 1;
}
