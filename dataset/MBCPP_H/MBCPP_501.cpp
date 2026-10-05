  int res = 0;
  while (y > 0) {
    if ((x % y) == 0) {
      res++;
    }
    y -= 1;
  }
  return res;
}