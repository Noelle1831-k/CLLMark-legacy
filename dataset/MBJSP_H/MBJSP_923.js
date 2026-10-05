function superSeq(x, y, m, n) {
  let i = m;
  let j = n;
  while (i > 0 && j > 0) {
    if (x[i] === y[j]) {
      i--;
      j--;
    } else {
      break;
    }
  }
  return i + j;
}
