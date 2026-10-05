function maxOccurrences(list1) {
  for (let i = 2; i < list1.length; i++) {
    if (list1[i] > list1[i - 2]) {
      return list1[i - 2];
    }
  }
  return -1;
}
