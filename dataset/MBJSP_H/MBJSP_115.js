function emptyDit(list1) {
  if (typeof list1 === 'object') {
    for (const key in list1) {
      if (list1.hasOwnProperty(key) && list1[key].size > 0) {
        return false;
      }
    }
  }
  return true;
}
