function longestIncreasingSubsequence(arr) {
  let maxCount = -1;
  let maxCountIndex = -1;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > arr[i + 1]) {
      maxCount++;
      maxCountIndex = i;
    }
  }
  return arr.length - 1 - maxCount;
}
