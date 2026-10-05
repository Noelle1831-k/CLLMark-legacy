int isDivisibleByDigits(int num) {
    int originalNum = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || originalNum % digit != 0) {
            return 0;
        }
        num /= 10;
    }
    return 1;
}
void divisibleByDigits(int startnum, int endnum, int result[], int *size) {
    *size = 0;
    for (int i = startnum; i <= endnum; i++) {
        if (isDivisibleByDigits(i)) {
            result[*size] = i;
            (*size)++;
        }
    }
}
