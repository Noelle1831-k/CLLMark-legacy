function minVal(listval) {
  let minVal = Infinity;
  listval.forEach(item => {
    if (item < minVal) {
      minVal = item;
    }
  });
  return minVal;
}
