function maxAbsDiff(arr, n) {
  const max = Math.max(...arr);
  const min = Math.min(...arr);
  const difference = Math.abs(max - min);
  return difference;
}
