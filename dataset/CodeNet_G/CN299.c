#define INF INT_MAX
typedef struct {
    int a, b, d;
    char order, distance;
} Constraint;
int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    Constraint constraints[C];
    for (int i = 0; i < C; i++) {
        char oi, si;
        scanf("%d%c%d%c%d", &constraints[i].a, &oi, &constraints[i].b, &si, &constraints[i].d);
        constraints[i].order = oi;
        constraints[i].distance = si;
    }
    int dist[N + 1];
    for (int i = 1; i <= N; i++) {
        dist[i] = i - 1;
    }
    for (int i = 0; i < C; i++) {
        int a = constraints[i].a;
        int b = constraints[i].b;
        int d = constraints[i].d;
        char oi = constraints[i].order;
        char si = constraints[i].distance;
        if (oi == '<') {
            if (dist[a] > dist[b]) {
                printf("-1\n");
                return 0;
            }
        } else if (oi == '>') {
            if (dist[a] < dist[b]) {
                printf("-1\n");
                return 0;
            }
        }
        if (si == '+') {
            if (abs(dist[a] - dist[b]) < d) {
                dist[a] = dist[b] + d;
                if (dist[a] > INF) {
                    printf("inf\n");
                    return 0;
                }
            }
        } else if (si == '-') {
            if (abs(dist[a] - dist[b]) > d) {
                printf("-1\n");
                return 0;
            }
        }
    }
    int max_distance = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > max_distance) {
            max_distance = dist[i];
        }
    }
    printf("%d\n", max_distance);
    return 0;
}