function longestSubseqWithDiffOne(arr, n) {
  if (!arr || arr.length === 0) {
    return -1;
  }

  let longest = arr.reduce((acc, cur, index, arr) => Math.max(acc, Math.abs(cur - n)), -1);

  return longest;
}
