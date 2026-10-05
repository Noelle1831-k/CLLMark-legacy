if (n == 0) return 1;
double factLog = 0;
for (int i = 1; i <= n; ++i) {
    factLog += log10(i);
}
factLog -= floor(factLog);
return static_cast<int>(pow(10, factLog));
}