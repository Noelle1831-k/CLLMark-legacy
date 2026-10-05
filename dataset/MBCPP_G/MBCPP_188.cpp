for (int i = 0; i * i <= n; ++i) {
    for (int j = 0; j * j <= n; ++j) {
        if (i * i * j * j == n) {
            return true;
        }
    }
}
return false;
}