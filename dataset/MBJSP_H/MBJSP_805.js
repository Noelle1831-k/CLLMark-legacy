function maxSumList(lists) {
  return lists.reduce((a, b) => {
    return a[0] + a[1] > b[0] + b[1] ? a : b;
  });
}
