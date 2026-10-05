function removeWords(list1, removewords) {
  return list1.filter((item) => removewords.indexOf(item) === -1);
}
