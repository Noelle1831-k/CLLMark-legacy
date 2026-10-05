function findFixedPoint(arr, n) {
  for (let i = 0; i < n; i++) {
    if (arr.indexOf(i) === i) {
      return arr.indexOf(i);
    }
  }
  return -1;
}
