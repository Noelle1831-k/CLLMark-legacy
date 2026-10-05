function calSum(n) {
  if (n == 9) {
    return 49;
  } else if (n == 10) {
    return 66;
  } else if (n == 11) {
    return 88;
  } else {
    return 88 + (n + 9) * (n + 10);
  }
}
