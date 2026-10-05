function primeNum(num) {
  if (num <= 0) {
    return false;
  }
  if (num < 10) {
    return true;
  }
  return primeNum(num % 10);
}
