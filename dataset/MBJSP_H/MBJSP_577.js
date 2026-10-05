function lastDigitFactorial(n) {
  if (n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 9 == 0) {
    return 0;
  } else {
    return n % 5;
  }
}
