if (n == 0 && k == 0) return 1;
if (k < 0 || k > n) return 0;
return zigzag(n - 1, k - 1) + zigzag(n - 1, k);
}