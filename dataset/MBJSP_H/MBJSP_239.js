function getTotalNumberOfSequences(m, n) {
  const T = new Array(m+1)
    .fill(0)
    .map(() => new Array(n+1).fill(0))
  for (let i = 0; i < m+1; i++) {
    for (let j = 0; j < n+1; j++) {
      if (i === 0 || j === 0) {
        T[i][j] = 0
      } else if (i < j) {
        T[i][j] = 0
      } else if (j === 1) {
        T[i][j] = i
      } else {
        T[i][j] = T[i - 1][j] + T[i >> 1][j - 1]
      }
    }
  }
  return T[m][n]
}
