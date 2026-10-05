function sumColumn(list1, c) {
  return list1.reduce((sum, value) => sum + value[c], 0);
}
