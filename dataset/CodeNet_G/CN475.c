typedef struct {
    int x, y;
} Facility;
int compare_sum(const void *a, const void *b) {
    Facility *fa = (Facility *)a;
    Facility *fb = (Facility *)b;
    int sum_a = fa->x + fa->y;
    int sum_b = fb->x + fb->y;
    return sum_a - sum_b;
}
int compare_diff(const void *a, const void *b) {
    Facility *fa = (Facility *)a;
    Facility *fb = (Facility *)b;
    int diff_a = fa->x - fa->y;
    int diff_b = fb->x - fb->y;
    return diff_a - diff_b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int compute_max_distance(Facility facilities[], int N) {
    qsort(facilities, N, sizeof(Facility), compare_sum);
    int max_sum_diff = facilities[N-1].x + facilities[N-1].y - (facilities[0].x + facilities[0].y);
    qsort(facilities, N, sizeof(Facility), compare_diff);
    int max_diff_diff = facilities[N-1].x - facilities[N-1].y - (facilities[0].x - facilities[0].y);
    return max(max_sum_diff, max_diff_diff);
}