function colonTuplex(tuplex, m, n) {
if (tuplex[m] instanceof Array) {
    tuplex[m].push(n);
  } else {
    tuplex[m] = n;
  }
  return tuplex;
}
