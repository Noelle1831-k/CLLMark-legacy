function binomialCoeff(n, k) {
  let binomialCoeff = 1;
  for (let i = 0; i < k; i++) {
    binomialCoeff *= (n - i) / (i + 1);
  }
  return binomialCoeff;
}
