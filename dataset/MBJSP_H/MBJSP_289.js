function oddDays(n) {
  if (n % 100 == 0) {
    return 5;
  }
  if (n % 50 == 0) {
    return 6;
  }
  if (n % 75 == 0) {
    return 2;
  }
  return 3;
}
