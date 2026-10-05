if (n == 0) return 1; 
if (n < 0 || m <= 0) return 0;
return coinChange(s, m - 1, n) + coinChange(s, m, n - s[m - 1]);
}