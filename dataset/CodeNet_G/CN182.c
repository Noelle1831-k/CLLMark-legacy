int cmp(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}
bool canFillAllBeakers(int* capacities, int n) {
    qsort(capacities, n, sizeof(int), cmp);
    int remaining = capacities[0];
    for (int i = 1; i < n; i++) {
        if (remaining <= 0) return false;
        if (capacities[i] <= remaining) {
            remaining -= capacities[i];
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int capacities[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &capacities[i]);
        }
        if (canFillAllBeakers(capacities, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}