function nthItems(list, n) {
  return list.filter((item, index) => index % n === 0);
}
