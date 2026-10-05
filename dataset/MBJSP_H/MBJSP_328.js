function rotateLeft(list1, m, n) {
  return list1.slice(m, list1.length).concat(list1.slice(0, n));
}
