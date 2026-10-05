function findMaxLength(lst) {
  return lst.length > 0 && lst[lst.length - 1].length > 0 ? lst[lst.length - 1].length : -1;
}
