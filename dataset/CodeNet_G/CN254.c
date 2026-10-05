void sort_desc(char *num) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num[i] < num[j]) {
                char temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}
void sort_asc(char *num) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num[i] > num[j]) {
                char temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}
int kaprekar_steps(int n) {
    if (n % 1111 == 0) return -1;
    int steps = 0;
    char num[5];
    while (n != 6174) {
        sprintf(num, "%04d", n);
        sort_desc(num);
        int L = atoi(num);
        sort_asc(num);
        int S = atoi(num);
        n = L - S;
        steps++;
    }
    return steps;
}