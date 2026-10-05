function sum(a, b) {
  var s = 0;
  for (let i = 1; i < b; i++) {
    if (a % i == 0 && b % i == 0) {
      s += i;
    }
  }
  return s;
}
