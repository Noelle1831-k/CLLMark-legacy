#define MAX_N 6000
#define MAX_LENGTH 6000
int lengths[MAX_N];
int bend_lengths[MAX_N];
int n, m, x, y;
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int count_unique_rp(int straight_count, int bent_count) {
    int rp_count = 0;
    int used_straight = 0, used_bent = 0;
    for (int i = 0; i < n; i++) {
        used_straight = 0;
        used_bent = 0;
        int l1 = lengths[i];
        for (int j = i + 1; j < n; j++) {
            int l2 = lengths[j];
            for (int k = j + 1; k < n; k++) {
                int l3 = lengths[k];
                int sides[3] = {l1, l2, l3};
                qsort(sides, 3, sizeof(int), compare);
                if (used_straight < y && used_bent > 0 && straight_count - used_straight >= y - 3) {
                    rp_count++;
                    break;
                } else if (used_bent < x && used_straight >= 3 && bent_count - used_bent >= x - 3) {
                    rp_count++;
                    break;
                }
                used_straight++;
                used_bent++;
            }
        }
    }
    return rp_count;
}
int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]);
    }
    for (int i = 0; i < m; i++) {
        int bend;
        scanf("%d", &bend);
        bend_lengths[i] = bend;
        lengths[i] -= bend; 
    }
    qsort(lengths, n, sizeof(int), compare);
    int result = count_unique_rp(m - x, n - m - y);
    printf("%d\n", result);
    return 0;
}
