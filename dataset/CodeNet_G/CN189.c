#define MAX_TOWNS 10
#define INF INT_MAX
void min_commute_town(int num_roads, int roads[][3]) {
    int dist[MAX_TOWNS][MAX_TOWNS];
    int total_commute[MAX_TOWNS];
    int num_towns = MAX_TOWNS;
    memset(dist, INF, sizeof(dist));
    memset(total_commute, 0, sizeof(total_commute));
    for (int i = 0; i < num_roads; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        int c = roads[i][2];
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int k = 0; k < num_towns; k++) {
        for (int i = 0; i < num_towns; i++) {
            for (int j = 0; j < num_towns; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    for (int start = 0; start < num_towns; start++) {
        for (int i = 0; i < num_towns; i++) {
            if (i != start && dist[start][i] < INF) {
                total_commute[start] += dist[start][i];
            }
        }
    }
    int min_sum = INF;
    int best_town = 0;
    for (int i = 0; i < num_towns; i++) {
        if (total_commute[i] < min_sum) {
            min_sum = total_commute[i];
            best_town = i;
        }
    }
    printf("%d %d\n", best_town, min_sum);
}