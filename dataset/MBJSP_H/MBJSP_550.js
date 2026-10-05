function findMax(arr, low, high) {
  return arr.reduce((max, item) => {
    if (item > max) {
      max = item;
    }
    return max;
  }, low);
}
