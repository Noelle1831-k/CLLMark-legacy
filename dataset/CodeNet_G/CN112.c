int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void calculate_minimum_wait_time(int n, int *times) {
    qsort(times, n, sizeof(int), compare);
    int total_wait_time = 0;
    int accumulated_time = 0;
    for (int i = 0; i < n; i++) {
        total_wait_time += accumulated_time;
        accumulated_time += times[i];
    }
    printf("%d\n", total_wait_time);
}