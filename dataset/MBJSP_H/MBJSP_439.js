function multipleToSingle(l) {
  return +l.sort((item, itemA) => {
    return item - itemA;
  }).join('') * 1;
}
