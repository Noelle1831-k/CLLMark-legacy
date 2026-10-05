#define MAX_N 100
#define MAX_M 5
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point location;
    int capacity;
    int fee;
} Venue;
typedef struct {
    Point location;
} Candidate;
int manhattan_distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int calculate_minimum_cost(int N, int M, int B, Candidate candidates[], Venue venues[]) {
    int min_cost = INT_MAX;
    for (int d = 0; d <= 2000; d++) {
        int assignment[MAX_N] = {0};
        int total_cost = 0;
        int venue_used[MAX_M] = {0};
        for (int i = 0; i < N; i++) {
            int min_distance = INT_MAX;
            int assigned_venue = -1;
            for (int j = 0; j < M; j++) {
                int distance = manhattan_distance(candidates[i].location, venues[j].location);
                if (distance <= d && distance < min_distance && assignment[i] < venues[j].capacity) {
                    min_distance = distance;
                    assigned_venue = j;
                }
            }
            if (assigned_venue == -1) {
                total_cost = INT_MAX;
                break;
            }
            assignment[i]++;
            venue_used[assigned_venue] = 1;
            total_cost += min_distance;
        }
        for (int j = 0; j < M; j++) {
            if (venue_used[j]) {
                total_cost += venues[j].fee;
                total_cost += d * B;
            }
        }
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
    }
    return min_cost;
}
