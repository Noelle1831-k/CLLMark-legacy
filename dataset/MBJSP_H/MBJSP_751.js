function checkMinHeap(arr, i) {
  let result = true;
  let j;
  let m;
  if (i === 0 && arr.length === 1) {
    // console.log('is it the first item of array')
    return result;
  }
  // console.log('is it the first item of array')
  for (j = 0; j < arr.length; j++) {
    m = j - 1;
    while (m >= 0 && arr[m] > arr[m + 1]) {
      arr[m + 1] = arr[m];
      m--;
    }
    if (arr[m] === arr[m + 1]) {
      result = false;
      break;
    }
  }
  return result;
}
