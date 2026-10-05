function countPairs(arr, n, k) {
  // <unk>��<unk>��<unk>��<unk>�� <unk>��<unk>��<unk>��<unk>��.
  let count = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (arr[i] - arr[j] === k) {
        count += 1;
      }
    }
  }
  return count;
}
