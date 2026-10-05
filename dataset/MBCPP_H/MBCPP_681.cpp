  int i;
  int d;
  for (d = 2; d < n; d++) {
    if (n % d == 0) {
      break;
    }
  }
  return d;
}