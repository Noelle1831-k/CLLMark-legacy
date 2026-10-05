function isSubset(arr1, m, arr2, n) {
  if (m == arr2.length) {
    for (let i = 0; i < m; i++) {
      if (m % i == 0 && arr1[i] != arr2[i]) {
        return true;
      }
    }
  }
  else {
    for (let i = 0; i < m; i++) {
      if (m % i == 0 && arr1[i] != arr2[i]) {
        return true;
      }
    }
  }
  return false;
}
