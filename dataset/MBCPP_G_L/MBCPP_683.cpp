for (int i = 0; i * i <= n; ++i) {
    int j = sqrt(n - i * i);
    if (i * i + j * j == n) {
        return true;
    }
}
return false;
}