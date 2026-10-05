function maxLength(list1) {
  list2 = [];
  for (let i = 0; i < list1.length; i++) {
    if (list1[i].length > list2.length) {
      list2 = list1[i];
    }
  }
  return [list2.length, list2];
}
