  vector<int> sum = {0, 0};
  for (int i = 0; i < testTuple.size(); i++) {
    if (i % 2) {
      sum[0] += testTuple[i];
    } else {
      sum[1] += testTuple[i];
    }
  }
  return sum;
}