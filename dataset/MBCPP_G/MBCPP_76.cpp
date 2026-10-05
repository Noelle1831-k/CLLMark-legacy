int totalSquares = 0;
for (int i = 1; i <= min(m, n); ++i) {
    totalSquares += (m - i + 1) * (n - i + 1);
}
return totalSquares;
}