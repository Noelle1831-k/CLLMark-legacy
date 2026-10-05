double q = 1.0 - p;
double binomial_coefficient = 1.0;
for (int i = 0; i < k; ++i) {
    binomial_coefficient *= (n - i) / static_cast<double>(i + 1);
}
return binomial_coefficient * pow(p, k) * pow(q, n - k);
}