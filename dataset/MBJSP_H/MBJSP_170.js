function sumRangeList(list1, m, n) {
  let result = 0;

  for (let i = m; i <= n; i++) {
    result += list1[i];
  }

  return result;
}
