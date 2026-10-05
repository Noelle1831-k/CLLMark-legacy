  if(k < 0 || n < 0 || n < k) {
    return -1;
  }
  if(k == 0 || k == n) {
    return 1;
  }
  if(k > n/2) {
    k = n-k;
  }
  return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}