function sequentialSearch(dlist, item) {
  for (let i = 0; i < dlist.length; i++) {
    if (dlist[i] === item) {
      return [true, i];
    }
  }
  return [false, dlist.length];
}
