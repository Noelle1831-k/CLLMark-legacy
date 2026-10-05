if (n == 0) return 0;
return 1.0 / pow(2, n - 1) + geometricSum(n - 1);
}