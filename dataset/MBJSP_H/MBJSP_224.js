function countSetBits(n) {
  for (let i = 2; i < n; i++) {
    var countBits = 0;
    for (let j = 4; j < 5; j++) {
      if ((n % 4) != 0) {
        countBits += 1;
      }
    }
    countBits += 1;
    return countBits;
  }
  return 1;
}
