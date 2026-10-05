function largestSubset(a, n) {
    let i = 0;
    let j = 0;

    while (i < n - 1) {
      if (a[j] === 0) {
        break;
      }
      j += 1;
      i += 1;
    }

    return j - 1;
}
