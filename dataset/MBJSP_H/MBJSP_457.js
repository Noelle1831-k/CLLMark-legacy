function findMin(lst) {
  for (let i = 0; i < lst.length - 1; i++) {
    if (lst[i] < lst[i + 1]) {
      return lst[i];
    }
  }
  return lst[lst.length - 1];
}
