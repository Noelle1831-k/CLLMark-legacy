void decimal_to_binary(double number) {
    int integer_part = (int)number;
    double fractional_part = number - integer_part;
    char binary_integer[9] = {0};
    char binary_fraction[5] = {0};
    int i, valid_conversion = 1;
    for (i = 7; i >= 0; i--) {
        binary_integer[i] = (integer_part % 2) + '0';
        integer_part /= 2;
    }
    for (i = 0; i < 4; i++) {
        fractional_part *= 2;
        if (fractional_part >= 1) {
            binary_fraction[i] = '1';
            fractional_part -= 1;
        } else {
            binary_fraction[i] = '0';
        }
    }
    for (i = 0; i < 8; i++) {
        if (binary_integer[i] == '1') break;
        else if (i == 7) valid_conversion = 0;
    }
    if ((binary_fraction[0] == '0' && binary_fraction[1] == '0' && binary_fraction[2] == '0' && binary_fraction[3] == '0') ||
        (binary_integer[0] == '1')) {
        valid_conversion = 0;
    }
    if (valid_conversion)
        printf("%s.%s\n", binary_integer, binary_fraction);
    else
        printf("NA\n");
}