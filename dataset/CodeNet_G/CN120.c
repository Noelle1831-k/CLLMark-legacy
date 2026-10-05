#define MAX_ROLLS 12
int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int can_fit_in_box(int rolls[], int n, int W) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 2 * rolls[i];
        if (sum <= W) return 1;
    }
    return 0;
}
int main() {
    int W, n, rolls[MAX_ROLLS];
    while (scanf("%d", &W) != EOF) {
        n = 0;
        while (scanf("%d", &rolls[n]) != EOF && rolls[n] >= 3 && rolls[n] <= 10) {
            n++;
            if (getchar() == '\n') break;
        }
        qsort(rolls, n, sizeof(int), compare);
        if (can_fit_in_box(rolls, n, W)) {
            printf("OK\n");
        } else {
            printf("NA\n");
        }
    }
    return 0;
}