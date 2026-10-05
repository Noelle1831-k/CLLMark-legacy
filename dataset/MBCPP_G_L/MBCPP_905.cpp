int result = 0;
vector<int> coefficients(n + 1, 1);
for (int i = 1; i <= n; ++i) {
    for (int j = i - 1; j > 0; --j) {
        coefficients[j] += coefficients[j - 1];
    }
}
for (int coef : coefficients) {
    result += coef * coef;
}
return result;
}