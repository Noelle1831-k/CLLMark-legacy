  int mls[n + 1];
  int max = 0;
  for(int i = 0; i < n + 1; i++) {
    mls[i] = 1;
  }
  for(int i = 1; i <= n ; i++) {
    for(int j = i - 1; j >= 0; j--) {
      if (abs(arr[i] - arr[j]) <= 1 && mls[i] < mls[j] + 1) {
        mls[i] = mls[j] + 1;
      }
    }
    if (mls[i] > max) {
      max = mls[i];
    }
  }
  return max;
}