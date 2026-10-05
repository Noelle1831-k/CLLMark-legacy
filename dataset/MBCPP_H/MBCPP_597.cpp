  int i = 0, j = 0, c = 0;
  while (i < m || j < n) {
    if (i == m) {
      c++;
      j++;
    } else if (j == n) {
      c++;
      i++;
    } else if (arr1[i] < arr2[j]) {
      c++;
      i++;
    } else {
      c++;
      j++;
    }
    if (c == k) {
      return arr1[i - 1];
    }
  }
  return -1;
}