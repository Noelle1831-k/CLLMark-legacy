function search(arr, n) {
  return arr.filter(item => arr.indexOf(item) === arr.lastIndexOf(item))[0];
}
