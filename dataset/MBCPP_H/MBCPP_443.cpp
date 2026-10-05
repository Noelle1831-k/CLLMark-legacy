  int negative = 0;
  for (int i : list1) {
    if (i < 0) {
      negative = i;
    }
  }
  return negative;
}