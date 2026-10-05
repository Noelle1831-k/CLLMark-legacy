  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return 2 * highestPowerOf2(n / 2);
  }
}