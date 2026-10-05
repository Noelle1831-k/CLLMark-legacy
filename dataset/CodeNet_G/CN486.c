typedef struct {
    int x, y;
} House;
int compare_x(const void *a, const void *b) {
    return ((House *)a)->x - ((House *)b)->x;
}
int compare_y(const void *a, const void *b) {
    return ((House *)a)->y - ((House *)b)->y;
}
long long calculate_total_distance(House *houses, int n, int tx, int ty) {
    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += abs(houses[i].x - tx);
        total_distance += abs(houses[i].y - ty);
    }
    return total_distance;
}
int main() {
    int w, h, n;
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    House *houses = (House *)malloc(n * sizeof(House));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &houses[i].x, &houses[i].y);
    }
    qsort(houses, n, sizeof(House), compare_x);
    int optimal_x = houses[(n - 1) / 2].x;
    qsort(houses, n, sizeof(House), compare_y);
    int optimal_y = houses[(n - 1) / 2].y;
    long long min_time = calculate_total_distance(houses, n, optimal_x, optimal_y);
    printf("%lld\n%d %d\n", min_time, optimal_x, optimal_y);
    free(houses);
    return 0;
}