if (k > n) return 0;
if (k == 0 || k == n) return 1;
return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}