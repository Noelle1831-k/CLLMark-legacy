#define MAX_DEPTH 20
int goal[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0};
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};
typedef struct {
    int state[13];
    int zero1;
    int zero2;
    int g;
} Puzzle;
int is_solvable(Puzzle *pz) {
    int inversions = 0;
    for (int i = 0; i < 13; i++) {
        if (pz->state[i] == 0) continue;
        for (int j = i + 1; j < 13; j++) {
            if (pz->state[j] == 0) continue;
            if (pz->state[i] > pz->state[j]) inversions++;
        }
    }
    return inversions % 2 == 0;
}
int is_goal(Puzzle *pz) {
    for (int i = 0; i < 13; i++) {
        if (pz->state[i] != goal[i]) return 0;
    }
    return 1;
}
int dfs(Puzzle *pz, int depth, int max_depth) {
    if (depth > max_depth) return 0;
    if (is_goal(pz)) return 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            int zero_pos = (j == 0) ? pz->zero1 : pz->zero2;
            int x = zero_pos % 4;
            int y = zero_pos / 4;
            int nx = x + dx[i];
            int ny = y + dy[i];
            int new_zero_pos = ny * 4 + nx;
            if (nx < 0 || nx > 3 || ny < 0 || ny > 2 || new_zero_pos == pz->zero1 || new_zero_pos == pz->zero2) continue;
            int backup = pz->state[new_zero_pos];
            pz->state[new_zero_pos] = 0;
            if (j == 0) {
                pz->state[pz->zero1] = backup;
                pz->zero1 = new_zero_pos;
            } else {
                pz->state[pz->zero2] = backup;
                pz->zero2 = new_zero_pos;
            }
            if (dfs(pz, depth + 1, max_depth)) return 1;
            if (j == 0) {
                pz->state[pz->zero1] = 0;
                pz->state[new_zero_pos] = backup;
                pz->zero1 = zero_pos;
            } else {
                pz->state[pz->zero2] = 0;
                pz->state[new_zero_pos] = backup;
                pz->zero2 = zero_pos;
            }
        }
    }
    return 0;
}
int solve_puzzle(Puzzle *pz) {
    if (!is_solvable(pz)) return -1;
    for (int max_depth = 0; max_depth <= MAX_DEPTH; max_depth++) {
        if (dfs(pz, 0, max_depth)) return max_depth;
    }
    return -1;
}