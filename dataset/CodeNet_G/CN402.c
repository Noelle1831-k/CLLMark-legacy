int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int min_meeting_time(int houses[], int n) {
    qsort(houses, n, sizeof(int), compare);
    int median = houses[n / 2];
    int min_time = 0;
    for (int i = 0; i < n; i++) {
        min_time += abs(houses[i] - median);
    }
    return min_time;
}