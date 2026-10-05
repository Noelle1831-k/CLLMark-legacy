void convert_to_joukouki_units(int m, int n) {
    unsigned long long int value = pow(m, n);
    const char* units[] = {"Man", "Oku", "Cho", "Kei", "Gai", "Jo", "JoJou", "Ko", "Kan"};
    const unsigned long long int unit_values[] = {10000LL, 10000LL * 10000, 10000LL * 10000 * 10000, 
                                                   10000LL * 10000 * 10000 * 10000, 
                                                   10000LL * 10000 * 10000 * 10000 * 10000,
                                                   10000LL * 10000 * 10000 * 10000 * 10000 * 10000, 
                                                   10000LL * 10000 * 10000 * 10000 * 10000 * 10000 * 10000, 
                                                   10000LL * 10000 * 10000 * 10000 * 10000 * 10000 * 10000 * 10000, 
                                                   10000LL * 10000 * 10000 * 10000 * 10000 * 10000 * 10000 * 10000 * 10000};
    int len_units = sizeof(units) / sizeof(units[0]);
    unsigned long long int quotients[len_units];
    for (int i = 0; i < len_units; i++) {
        quotients[i] = value / unit_values[i];
        value %= unit_values[i];
    }
    int has_output = 0;
    for (int i = len_units - 1; i >= 0; i--) {
        if (quotients[i] > 0) {
            if (has_output) printf(" ");
            printf("%llu%s", quotients[i], units[i]);
            has_output = 1;
        }
    }
    if (value > 0 || !has_output) {
        if (has_output) printf(" ");
        printf("%llu", value);
    }
    printf("\n");
}