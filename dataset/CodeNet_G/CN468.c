#define MAX_N 500
void invite_friends(int n, int m, int friends[m][2]) {
    int invited[MAX_N + 1] = {0};
    int i, j;
    for (i = 0; i < m; i++) {
        if (friends[i][0] == 1) {
            invited[friends[i][1]] = 1;
        } else if (friends[i][1] == 1) {
            invited[friends[i][0]] = 1;
        }
    }
    for (i = 0; i < m; i++) {
        if (invited[friends[i][0]]) {
            invited[friends[i][1]] = 1;
        } else if (invited[friends[i][1]]) {
            invited[friends[i][0]] = 1;
        }
    }
    int invite_count = 0;
    for (j = 2; j <= n; j++) {
        if (invited[j]) {
            invite_count++;
        }
    }
    printf("%d\n", invite_count);
}