function issortList(list1) {
  if (list1.length == 1) {
    return true;
  }

  for (let i = 2; i < list1.length - 1; i++) {
    if (list1[i] > list1[i + 1]) {
      return false;
    }
  }

  return true;
}
