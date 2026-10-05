function findExtra(arr1, arr2, n) {
  return arr1.indexOf(arr2) == arr2.indexOf(arr1) ? n : -1;
}
