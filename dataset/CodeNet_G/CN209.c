#define MAX_N 100
#define MAX_M 50
int n, m;
int w[MAX_N][MAX_N];
int p[MAX_M][MAX_M];
int rotate_match(int img[MAX_N][MAX_N], int row, int col) {
    int match, i, j, x, y, pi, pj;
    for (int r = 0; r < 4; r++) {
        match = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                if (p[i][j] == -1) continue;
                x = i; y = j;
                if (r == 1) { pi = j; pj = m - 1 - i; }
                else if (r == 2) { pi = m - 1 - i; pj = m - 1 - j; }
                else if (r == 3) { pi = m - 1 - j; pj = i; }
                else { pi = i; pj = j; }
                if (img[row + pi][col + pj] != p[i][j]) {
                    match = 0;
                    break;
                }
            }
            if (!match) break;
        }
        if (match) return 1;
    }
    return 0;
}
void find_match() {
    int found = 0;
    int min_x = n, min_y = n;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (rotate_match(w, i, j)) {
                found = 1;
                if (i < min_x || (i == min_x && j < min_y)) {
                    min_x = i;
                    min_y = j;
                }
            }
        }
    }
    if (found) {
        printf("%d %d\n", min_x, min_y);
    } else {
        printf("NA\n");
    }
}
void read_data() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
}
int main() {
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        read_data();
        find_match();
    }
    return 0;
}