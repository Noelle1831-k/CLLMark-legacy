if (m == 0 && n == 0) return 1;
if (m == 1) return 0;
if (n == 0) return 0;
return (n - 1) * (rencontresNumber(n - 1, m) + rencontresNumber(n - 2, m - 1));
}