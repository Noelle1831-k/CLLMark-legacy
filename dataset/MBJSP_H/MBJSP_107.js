function countHexadecimal(l, r) {
  var count = 0;
  for (let i = l; i <= r; i++) {
    if (i >= 10 && i <= 15) {
      count++;
    }
  }
  return count;
}
