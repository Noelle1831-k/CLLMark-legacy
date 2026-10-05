function leftInsertion(a, x) {
  for (let i = 0; i < a.length; i++) {
    if (a[i] < x) {
      let index = i + 1;
      while (a[index] < x) {
        index ++;
      }
      a[i] = index;
    }
  }
  return a[0];
}
