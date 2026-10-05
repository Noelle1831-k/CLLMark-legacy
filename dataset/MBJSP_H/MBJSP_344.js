function countOddSquares(n, m) {
  let count = 0;
  for (let i = n; i <= m; i++) {
    let sqrt = Math.sqrt(i);
    if (sqrt % 1 === 0) {
      count++;
    }
  }
  return count;
}
