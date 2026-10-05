function getFirstSetBitPos(n) {
  let firstSetBitPos = 0;
  for (let i = 0; i < 32; i++) {
    if (n & 1) {
      return (firstSetBitPos + 1);
    }
    firstSetBitPos += 1;
    n >>= 1;
  }
  return -1;
}
