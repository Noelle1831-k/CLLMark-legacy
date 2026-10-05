int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int calculate_min_cost(int N, int M, int p, int shopping_stations[]) {
    qsort(shopping_stations, M, sizeof(int), cmp);
    int total_cost = N * 100;
    for (int i = 0; i < M; i++) {
        int clockwise_distance = (shopping_stations[i] - p + N) % N;
        int cost_clockwise = clockwise_distance * 100;
        int anti_clockwise_distance = (p - shopping_stations[i] + N) % N;
        int cost_anti_clockwise = anti_clockwise_distance * 100;
        int this_trip_cost = 0;
        this_trip_cost += cost_clockwise;
        int last_pos = shopping_stations[i];
        int clockwise_next_cost = 0;
        for (int j = i + 1; j < M; j++) {
            int distance = (shopping_stations[j] - last_pos + N) % N;
            clockwise_next_cost += distance * 100;
            last_pos = shopping_stations[j];
        }
        int anti_clockwise_next_cost = 0;
        last_pos = shopping_stations[i];
        for (int j = i - 1; j >= 0; j--) {
            int distance = (last_pos - shopping_stations[j] + N) % N;
            anti_clockwise_next_cost += distance * 100;
            last_pos = shopping_stations[j];
        }
        int total_clockwise_cost = this_trip_cost + min(clockwise_next_cost, anti_clockwise_next_cost);
        total_cost = min(total_cost, total_clockwise_cost);
        this_trip_cost = 0;
        this_trip_cost += cost_anti_clockwise;
        last_pos = shopping_stations[i];
        clockwise_next_cost = 0;
        for (int j = i + 1; j < M; j++) {
            int distance = (shopping_stations[j] - last_pos + N) % N;
            clockwise_next_cost += distance * 100;
            last_pos = shopping_stations[j];
        }
        anti_clockwise_next_cost = 0;
        last_pos = shopping_stations[i];
        for (int j = i - 1; j >= 0; j--) {
            int distance = (last_pos - shopping_stations[j] + N) % N;
            anti_clockwise_next_cost += distance * 100;
            last_pos = shopping_stations[j];
        }
        int total_anti_clockwise_cost = this_trip_cost + min(clockwise_next_cost, anti_clockwise_next_cost);
        total_cost = min(total_cost, total_anti_clockwise_cost);
    }
    return total_cost;
}