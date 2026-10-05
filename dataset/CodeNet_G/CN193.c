#define MAX 100
int dx[] = { 0, 1, 1, 0, -1, -1 };
int dy_odd[] = { 1, 1, 0, -1, 0, 1 };
int dy_even[] = { 1, 0, -1, -1, -1, 0 };
int m, n, s, t;
int existing_stores[10][2];
int candidate_stores[10][2];
int grid_distance(int x1, int y1, int x2, int y2) {
    int ax = abs(x1 - x2);
    int ay = abs(y1 - y2);
    if ((x1 - 1) % 2 == 0) {
        y2 += (x1 - x2) / 2;
    }
    else {
        y1 += (x2 - x1) / 2;
    }
    return ax + (abs(y1 - y2) + 1) / 2;
}
int cover_count(int px, int py) {
    int cover_count = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int d_p = grid_distance(px, py, i, j);
            int min_dist = INT_MAX;
            for (int k = 0; k < s; k++) {
                int dist = grid_distance(existing_stores[k][0], existing_stores[k][1], i, j);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
            if (d_p < min_dist) {
                cover_count++;
            }
        }
    }
    return cover_count;
}
int main(void) {
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        scanf("%d", &s);
        for (int i = 0; i < s; i++) {
            scanf("%d %d", &existing_stores[i][0], &existing_stores[i][1]);
        }
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            scanf("%d %d", &candidate_stores[i][0], &candidate_stores[i][1]);
        }
        int max_cover = 0;
        for (int i = 0; i < t; i++) {
            int cover = cover_count(candidate_stores[i][0], candidate_stores[i][1]);
            if (cover > max_cover) {
                max_cover = cover;
            }
        }
        printf("%d\n", max_cover);
    }
    return 0;
}
