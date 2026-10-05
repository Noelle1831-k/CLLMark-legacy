int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void reduce_fraction(int *num, int *den) {
    int divisor = gcd(*num, *den);
    *num /= divisor;
    *den /= divisor;
}
void to_irreducible_fraction(const char *str, char *result) {
    int len = strlen(str);
    char integer_part[9] = {0};
    char non_repeating[9] = {0};
    char repeating[9] = {0};
    int i = 0, j = 0;
    while (i < len && str[i] != '.' && str[i] != '(') {
        integer_part[j++] = str[i++];
    }
    if (i < len && str[i] == '.') {
        i++;
        j = 0;
        while (i < len && str[i] != '(') {
            non_repeating[j++] = str[i++];
        }
    }
    if (i < len && str[i] == '(') {
        i++;
        j = 0;
        while (i < len && str[i] != ')') {
            repeating[j++] = str[i++];
        }
    }
    int integer_value = atoi(integer_part);
    int non_repeating_value = atoi(non_repeating);
    int repeating_value = atoi(repeating);
    int non_repeating_length = strlen(non_repeating);
    int repeating_length = strlen(repeating);
    int base_num = 0, base_den = 0;
    if (repeating_length > 0) {
        base_num = non_repeating_value;
        int p10_non = 1;
        for (i = 0; i < non_repeating_length; i++) p10_non *= 10;
        base_num = base_num * (p10_non - 1) + repeating_value;
        base_den = p10_non * (1 - pow(10, -repeating_length));
    } else {
        base_num = non_repeating_value;
        base_den = 1;
        for (i = 0; i < non_repeating_length; i++) base_den *= 10;
    }
    int integer_denominator = 1;
    int total_den = base_den;
    while (total_den % 10 == 0) {
        total_den /= 10;
        integer_denominator *= 10;
    }
    int total_num = integer_value * base_den + base_num;
    reduce_fraction(&total_num, &total_den);
    sprintf(result, "%d/%d", total_num, total_den);
}