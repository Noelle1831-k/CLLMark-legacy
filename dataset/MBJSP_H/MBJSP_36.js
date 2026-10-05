function findNthDigit(p, q, n) {
  // console.log(p / q);
  let a = p / q;
  let b = Math.floor(a);
  let c = a - b;
  let d = n - 1;
  while (d >= 0) {
    a = c * 10;
    b = Math.floor(a);
    c = a - b;
    d--;
  }
  return b;
}
