  int i = 0;
  int j = 0;
  double m1 = -1;
  double m2 = -1;
  int count = 0;
  while (count < n + 1) {
    count++;
    if (i == n) {
      m1 = m2;
      m2 = arr2[0];
      break;
    }
    if (j == n) {
      m1 = m2;
      m2 = arr1[0];
      break;
    }
    if (arr1[i] <= arr2[j]) {
      m1 = m2;
      m2 = arr1[i];
      i++;
    } else {
      m1 = m2;
      m2 = arr2[j];
      j++;
    }
  }
  return (m1 + m2)/2;
}