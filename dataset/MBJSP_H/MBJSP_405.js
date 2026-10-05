function checkTuplex(tuplex, tuple1) {
  for (let i = tuplex.length - 1; i >= 0; i--) {
    if (tuplex[i] == tuple1) {
      return true;
    }
  }
  return false;
}
