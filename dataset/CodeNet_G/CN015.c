void process_datasets(int n) {
    for (int i = 0; i < n; i++) {
        char num1[101], num2[101];
        scanf("%s", num1);
        scanf("%s", num2);
        if (strlen(num1) > 80 || strlen(num2) > 80) {
            printf("overflow\n");
            continue;
        }
        int len1 = strlen(num1);
        int len2 = strlen(num2);
        int max_len = len1 > len2 ? len1 : len2;
        int carry = 0, sum;
        char result[102];
        result[max_len + 1] = '\0';
        for (int j = 0; j < max_len; j++) {
            int digit1 = (len1 - 1 - j >= 0) ? num1[len1 - 1 - j] - '0' : 0;
            int digit2 = (len2 - 1 - j >= 0) ? num2[len2 - 1 - j] - '0' : 0;
            sum = digit1 + digit2 + carry;
            result[max_len - j] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry) {
            printf("overflow\n");
            continue;
        }
        if (strchr(result, '0') == result) {
            printf("%s\n", result + 1);
        } else {
            printf("%s\n", result);
        }
    }
}