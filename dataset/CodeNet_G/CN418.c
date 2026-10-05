#define MAX_N 100000
#define MAX_R 100000
typedef struct {
    int t, e;
} Equipment;
typedef struct {
    int a, b, c;
} Rule;
int N, R;
Equipment equipments[MAX_N + 1];
Rule rules[MAX_R];
long long dp[MAX_N + 1];
long long find_max_calories() {
    for (int i = 1; i <= N; i++) {
        dp[i] = (long long)equipments[i].t * equipments[i].e;
    }
    for (int i = 0; i < R; i++) {
        int a = rules[i].a, b = rules[i].b, c = rules[i].c;
        long long limit = (long long)c * equipments[a].e;
        if (equipments[b].e > 0) {
            limit += dp[b];
        }
        if (dp[a] > limit) {
            dp[a] = limit;
        }
    }
    long long max_calories = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > max_calories) {
            max_calories = dp[i];
        }
    }
    return max_calories;
}
int main() {
    scanf("%d %d", &N, &R);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &equipments[i].t, &equipments[i].e);
    }
    for (int i = 0; i < R; i++) {
        scanf("%d %d %d", &rules[i].a, &rules[i].b, &rules[i].c);
    }
    printf("%lld\n", find_max_calories());
    return 0;
}
