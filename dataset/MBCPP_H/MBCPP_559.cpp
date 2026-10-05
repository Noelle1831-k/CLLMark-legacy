  int maxSum = 0;
  int curSum = 0;
  for (int i = 0; i < size; i++) {
    curSum = 0;
    for (int j = i; j < size; j++) {
      curSum += a[j];
      if (curSum > maxSum) {
        maxSum = curSum;
      }
    }
  }
  return maxSum;
}