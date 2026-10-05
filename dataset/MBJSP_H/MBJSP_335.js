function apSum(a, n, d) {
  var sum = 0;
  for (var i = 0; i < n; i++) {
    sum += a + i * d;
  }
  return sum;
}
