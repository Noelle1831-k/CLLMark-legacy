  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) {
        return (n - i - 1) % 2;
      }
    }
  }
  return 1;
}