function mulEvenOdd(list1) {
  for (let index = 0; index < list1.length; index++) {
    if (list1[index] % 2 == 0) {
      return list1[index];
    }
  }
  return 0;
}
