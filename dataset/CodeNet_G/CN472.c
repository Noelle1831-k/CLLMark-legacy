int calculate_total_distance(int n, int m, int* distances, int* moves) {
    int current_location = 0;
    long long total_distance = 0;
    for (int i = 0; i < m; i++) {
        int next_location = current_location + moves[i];
        if (moves[i] > 0) {
            for (int j = current_location; j < next_location; j++) {
                total_distance += distances[j];
            }
        } else {
            for (int j = current_location - 1; j >= next_location; j--) {
                total_distance += distances[j];
            }
        }
        current_location = next_location;
    }
    return total_distance % 100000;
}