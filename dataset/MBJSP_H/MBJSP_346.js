function zigzag(n, k) {
  let count = 0;
  for (let i = 0; i < k; i++) {
    for (let j = i; j < n; j++) {
      if (n % j === 0) {
        count++;
      }
    }
  }
  return count;
}
