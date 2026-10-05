function concatenateElements(list) {
  return list.reduce(function (str, item) {
    return str + " " + item;
  }, " ");
}
