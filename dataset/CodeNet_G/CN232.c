#define MAX_X 4
#define MAX_Y 50
int main() {
    int X, Y, Z;
    int V[MAX_X], N[MAX_Y], E[MAX_Y], A[MAX_Y];
    double dp[MAX_Y + 1][101];
    while (1) {
        scanf("%d %d %d", &X, &Y, &Z);
        if (X == 0 && Y == 0 && Z == 0) break;
        for (int i = 0; i < X; i++) {
            scanf("%d", &V[i]);
        }
        for (int i = 0; i < Z; i++) {
            scanf("%d %d %d", &N[i], &E[i], &A[i]);
        }
        for (int i = 0; i <= Y; i++) {
            for (int j = 0; j <= 100; j++) {
                dp[i][j] = -1.0;
            }
        }
        dp[0][0] = 1.0;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j <= 100; j++) {
                if (dp[i][j] < 0.0) continue;
                for (int l = 0; l < X; l++) {
                    int nxt = i + V[l];
                    int money = j;
                    if (nxt >= Y) {
                        dp[Y][money] += dp[i][j] / X;
                        continue;
                    }
                    int event_index = -1;
                    for (int e = 0; e < Z; e++) {
                        if (N[e] == nxt) {
                            event_index = e;
                            break;
                        }
                    }
                    if (event_index != -1) {
                        if (E[event_index] == 1) {
                            nxt += A[event_index];
                            if (nxt >= Y) {
                                dp[Y][money] += dp[i][j] / X;
                                continue;
                            }
                        } else if (E[event_index] == 2) {
                            money += A[event_index];
                            if (money > 100) money = 100;
                        } else if (E[event_index] == 3) {
                            money -= A[event_index];
                            if (money < 0) money = 0;
                        }
                    }
                    dp[nxt][money] += dp[i][j] / X;
                }
            }
        }
        double expected_money = 0.0;
        for (int j = 0; j <= 100; j++) {
            if (dp[Y][j] > 0.0) {
                expected_money += j * dp[Y][j];
            }
        }
        printf("%d\n", (int)floor(expected_money));
    }
    return 0;
}
