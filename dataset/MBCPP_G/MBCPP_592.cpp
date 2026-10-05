int result = 0;
for (int k = 0; k <= n; ++k) {
    result += pow(2, k) * pow(2, n - k) * tgamma(n + 1) / (tgamma(k + 1) * tgamma(n - k + 1));
}
return result;
}