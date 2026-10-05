function countElementInList(list1, x) {
  return list1.filter(item => item.indexOf(x) > -1).length;
}
