function lenLog(list1) {
  let minLen = list1.length;
  for (let i = 0; i < list1.length; i++) {
    if (list1[i].length < minLen) {
      minLen = list1[i].length;
    }
  }
  return minLen;
}
