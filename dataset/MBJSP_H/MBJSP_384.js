function frequencyOfSmallest(n, arr) {
  return arr.filter(item => Math.abs(item - n) < Math.abs(item - n / 2)).length;
}
