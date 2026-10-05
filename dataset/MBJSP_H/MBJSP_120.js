function maxProductTuple(list1) {
  let max = 0;
  list1.forEach((item) => {
    max = Math.max(max, Math.abs(item[0] * item[1]));
  });
  return max;
}
