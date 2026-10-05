function averageEven(n) {
  if (n % 2 == 0) {
    return (n + 2) / 2;
  } else if (n % 4 == 0) {
    return n / 4;
  } else if (n % 5 == 0) {
    return n / 5;
  } else if (n % 6 == 0) {
    return n / 6;
  } else if (n % 7 == 0) {
    return n / 7;
  } else if (n % 9 == 0) {
    return n / 9;
  } else {
    return 0;
  }
}
