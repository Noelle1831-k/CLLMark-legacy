function findMinLength(lst) {
  var maxIndex = 0;
  for (let i = 1; i <= lst.length - 1; i++) {
    for (let j = i + 1; j <= lst.length; j++) {
      if (lst[i] > lst[j]) {
        maxIndex = j;
      }
    }
  }
  if (maxIndex >= 0) {
    return lst[maxIndex].length;
  }
  return 0;
}
