int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void solve(int sticks[12]) {
    qsort(sticks, 12, sizeof(int), cmp);
    for (int i = 0; i < 12; i += 4) {
        if (sticks[i] != sticks[i+3]) {
            printf("no\n");
            return;
        }
    }
    printf("yes\n");
}