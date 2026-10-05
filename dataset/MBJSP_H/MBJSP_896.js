function sortListLast(tuples) {
  return tuples.sort((a, b) => {
    return a[1] - b[1];
  });
}
