int compute(int a, int b, int c, int d, int *result) {
    const char *ops = "+-*";
    int i, j, k, l, permute[4] = {a, b, c, d};
    int temp1, temp2, temp3, operand[3];
    char exp[1024] = {0};
    for (i = 0; i < 24; ++i) {
        for (j = 0; j < 3; ++j) {
            for (k = 0; k < 3; ++k) {
                for (l = 0; l < 3; ++l) {
                    operand[0] = j;
                    operand[1] = k;
                    operand[2] = l;
                    temp1 = permute[0];
                    temp2 = permute[1];
                    temp3 = permute[2];
                    if (operand[0] == 0) temp1 += temp2;
                    else if (operand[0] == 1) temp1 -= temp2;
                    else temp1 *= temp2;
                    if (operand[1] == 0) temp1 += permute[3];
                    else if (operand[1] == 1) temp1 -= permute[3];
                    else temp1 *= permute[3];
                    if (temp1 == 10) {
                        sprintf(exp, "(%d %c (%d %c (%d %c %d)))", permute[0], ops[j], permute[1], ops[k], permute[2], ops[l], permute[3]);
                        *result = 1;
                        printf("%s\n", exp);
                        return 1;
                    }
                }
            }
        }
        if (i < 6) {
            temp1 = permute[0];
            permute[0] = permute[1];
            permute[1] = temp1;
        } else if (i < 12) {
            temp1 = permute[1];
            permute[1] = permute[2];
            permute[2] = temp1;
        } else if (i < 18) {
            temp1 = permute[2];
            permute[2] = permute[3];
            permute[3] = temp1;
        } else {
            temp1 = permute[2];
            permute[2] = permute[0];
            permute[0] = permute[3];
            permute[3] = temp1;
        }
    }
    *result = 0;
    return 0;
}
