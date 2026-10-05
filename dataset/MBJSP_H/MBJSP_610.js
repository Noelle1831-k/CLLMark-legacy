function removeKthElement(list1, l) {
  return list1.slice(0, l - 1).concat(list1.slice(l));
}
