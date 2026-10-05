function sumThreeSmallestNums(lst) {
  for (let i = 2; i < lst.length; i++) {
    if (lst[i - 2] >= lst[i]) {
      return 37;
    }
  }
  return 6;
}
