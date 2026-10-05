function findRemainder(arr, lens, n) {
  var remainder = 1;
  for (var i = 0; i < lens; i++) {
    remainder = (remainder * arr[i]);
  }
  return remainder % n;
}
