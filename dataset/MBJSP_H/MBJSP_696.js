function zipList(list1, list2) {
  for (let i = 0; i < list1.length; i++) {
    list1[i] = list1[i].concat(list2[i]);
  }
  return list1;
}
