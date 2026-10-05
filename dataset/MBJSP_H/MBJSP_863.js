function findLongestConseqSubseq(arr, n) {
  let m = 0;
  let max = 0;
  let start = 0;
  for (let i = 0; i < n; i++) {
    let j = i;
    while (j < n && arr[j] - arr[i] <= 1) {
      j++;
    }
    if (j - i > m) {
      m = j - i;
      start = i;
    }
  }
  return max = m;
}
