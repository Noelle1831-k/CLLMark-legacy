#define MAX_N 100000
#define MAX_M 10000
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
long long solve(int d, int n, int m, int positions[], int orders[]) {
    positions[n] = d;
    long long total_distance = 0;
    for (int i = 0; i < m; i++) {
        int k = orders[i];
        int *lower = lower_bound(positions, positions + n, k);
        int c1 = lower - positions;
        int c2 = (c1 + n - 1) % n;
        int distance1 = (positions[c1] + d - k) % d;
        int distance2 = (k + d - positions[c2]) % d;
        total_distance += (distance1 < distance2) ? distance1 : distance2;
    }
    return total_distance;
}
int* lower_bound(int* start, int* end, int target) {
    int* mid;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (*mid < target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}