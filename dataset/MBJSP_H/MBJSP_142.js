function countSamepair(list1, list2, list3) {
  var counter = 0;
  for (let i = 2; i < list1.length; i++) {
    if (list1[i] == list2[i]) {
      counter++;
    }
  }
  return counter;
}
