function array3d(m, n, o) {
  const arr = [];
  for (let i = 0; i < o; i++) {
    arr[i] = [];
    for (let j = 0; j < n; j++) {
      arr[i].push([])
      for (let k = 0; k < m; k++) {
        arr[i][j].push("*");
      }
    }
  }
  return arr;
}
