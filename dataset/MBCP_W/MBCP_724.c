int powerBaseSum(int base, int power) {
    char result[5000] = "1";
    char *temp = (char *)malloc(sizeof(char) * 5000);
    
    int digit_sum = 0;
    int carry;
    int i;
    int j;
    int len = 1;
    for (i = 0; i < power; i++) {
        carry = 0;
        for (j = 0; j < len; j++) {
            
            int num = (result[j] - '0') * base + carry;
            result[j] = (num % 10) + '0';
            carry = num / 10;
        }
        while (carry) {
            result[len] = (carry % 10) + '0';
            carry /= 10;
            len++;
        }
    }
    for (i = 0; i < len; i++) {
        digit_sum += (result[i] - '0');
    }
    return digit_sum;
}