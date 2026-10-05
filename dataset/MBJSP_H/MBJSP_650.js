function areEqual(arr1, arr2, n, m) {
  for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
      if (arr1[i] == arr2[j]) {
        return true;
      }
    }
    return false;
  }
  return true;
}
