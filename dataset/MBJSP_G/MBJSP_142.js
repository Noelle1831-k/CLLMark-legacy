function countSamepair(list1, list2, list3) {
let count = 0;
  for (let i = 0; i < list1.length; i++) {
    if (list1[i] === list2[i] && list2[i] === list3[i]) {
      count++;
    }
  }
  return count;
}
