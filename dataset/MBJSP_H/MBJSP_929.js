function countTuplex(tuplex, value) {
  let count = 0;
  for (let i = 0; i < tuplex.length; i++) {
    if (tuplex[i] === value) {
      count++;
    }
  }
  return count;
}
