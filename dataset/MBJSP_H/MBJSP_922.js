function maxProduct(arr) {
  let max1 = arr[0], max2 = arr[0];
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] * arr[j] > max1 * max2) {
        max1 = arr[i];
        max2 = arr[j];
      }
    }
  }
  return [max1, max2];
}
