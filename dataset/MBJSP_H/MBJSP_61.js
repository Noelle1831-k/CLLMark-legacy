function countSubstrings(s, n) {
  let count = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j <= n; j++) {
      if (s.slice(i, j).split('').reduce((acc, item) => acc + Number(item), 0) === j - i) {
        count += 1;
      }
    }
  }
  return count;
}
