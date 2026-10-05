function ncrModP(n, r, p) {
  let result = 1;
  for (let i = 0; i < r; i++) {
    result *= (n - i) / (i + 1);
  }
  return ((result % p) + p) % p;
}
