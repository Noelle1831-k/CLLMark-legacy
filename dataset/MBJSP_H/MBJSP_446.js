function countOccurrence(tup, lst) {
  let count = 0;

  tup.forEach((item, index) => {
    if (lst.indexOf(item) > -1) {
      count += 1;
    }
  });

  return count;
}
