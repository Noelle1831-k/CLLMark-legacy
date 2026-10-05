function decimalToBinary(n) {
  let b = n.toString(2);
  if (b.length < 2) {
    b = '0' + b;
  }
  return parseInt(b);
}
