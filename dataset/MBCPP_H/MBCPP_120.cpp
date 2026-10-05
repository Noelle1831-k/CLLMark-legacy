  int max = 0;
  for (vector<int> elem: list1) {
    int m = 1;
    for (int i: elem) m *= i;
    if (max < m) max = m;
  }
  return max;
}