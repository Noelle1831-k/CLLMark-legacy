function lenLog(list1) {
  let lenLog = 0;
  for (let i = 0; i < list1.length; i++) {
    if (list1[i].length > lenLog) {
      lenLog = list1[i].length;
    }
  }
  return lenLog;
}
