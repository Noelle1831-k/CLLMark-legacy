  if (n <= 3) {
    return 4;
  }
  int m = 2;
  while (m * m <= n) {
    m++;
  }
  return m * m;
}