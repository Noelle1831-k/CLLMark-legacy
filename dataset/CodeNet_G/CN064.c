int main() {
    char c;
    int sum = 0, number = 0;
    int in_number = 0;
    while (scanf("%c", &c) != EOF) {
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
            in_number = 1;
        } else {
            if (in_number) {
                sum += number;
                number = 0;
                in_number = 0;
            }
        }
    }
    if (in_number) {
        sum += number;
    }
    printf("%d\n", sum);
    return 0;
}