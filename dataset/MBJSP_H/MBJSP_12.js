function sortMatrix(m) {
  return m.sort((a, b) => {
    return a[0] * a[1] - b[0] * b[1];
  });
}
