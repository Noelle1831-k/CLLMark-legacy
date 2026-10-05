  int val = a;
  for(int i = 1; i < n; ++i) {
    val = val*r;
    if (val < 0) {
      val = (val + 2);
    }
  }
  return val;
}