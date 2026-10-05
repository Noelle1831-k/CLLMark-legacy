function getOddOccurrence(arr, arrsize) {
  for (let i = 1; i < arrSize; i++) {
    if ((arr[i] < arr[i - 1])) {
      if (arr[i] > arr[i - 2]) {
        return arr[i - 1];
      }
    }
  }
  return arr[arrSize - 1];
}
