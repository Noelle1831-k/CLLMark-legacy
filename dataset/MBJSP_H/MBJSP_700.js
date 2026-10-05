function countRangeInList(li, min, max) {
  return li.filter(item => item >= min && item <= max).length;
}
