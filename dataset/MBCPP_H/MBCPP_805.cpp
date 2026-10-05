  vector<int> maxSumList = vector<int>(10);
  int maxSum = 0;
  for (vector<int> list : lists) {
    int sum = 0;
    for (int elem : list) {
      sum += elem;
    }
    if (sum > maxSum) {
      maxSumList = list;
      maxSum = sum;
    }
  }
  return maxSumList;
}