bool is_valid(char *left, char *right, char *result, int x_value) {
    for (int i = 0; left[i]; i++) {
        if (left[i] == 'X') left[i] = x_value + '0';
    }
    for (int i = 0; right[i]; i++) {
        if (right[i] == 'X') right[i] = x_value + '0';
    }
    for (int i = 0; result[i]; i++) {
        if (result[i] == 'X') result[i] = x_value + '0';
    }
    long long left_value = atoll(left);
    long long right_value = atoll(right);
    long long result_value = atoll(result);
    return left_value + right_value == result_value;
}
void solve(char *input) {
    char *plus_sign = strchr(input, '+');
    char *equals_sign = strchr(input, '=');
    if (!plus_sign || !equals_sign) return;
    *plus_sign = *equals_sign = '\0';
    char *left = input;
    char *right = plus_sign + 1;
    char *result = equals_sign + 1;
    for (int x_value = 0; x_value <= 9; x_value++) {
        if (is_valid(left, right, result, x_value)) {
            printf("%d\n", x_value);
            return;
        }
    }
    printf("NA\n");
}
