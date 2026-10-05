function maxProductTuple(list1) {
const products = list1.map(pair => pair[0] * pair[1]);
  return Math.max(...products);
}
