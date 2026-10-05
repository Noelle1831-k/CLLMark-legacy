  int i, l = 0, r = a.size() - 1;
  while (l <= r) {
    i = l + (r - l) / 2;
    if (x < a[i]) {
      r = i - 1;
    } else {
      l = i + 1;
    }
  }
  return l;
}