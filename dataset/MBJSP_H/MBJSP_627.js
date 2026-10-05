function findFirstMissing(array, start, end) {
  let sortedArray = array.sort();
  for (let i = start; i < end; i++) {
    if (sortedArray[i] !== i) {
      return i;
    }
  }
  return sortedArray[end] + 1;
}
