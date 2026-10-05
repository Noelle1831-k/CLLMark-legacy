int n, m, h, d;
int ladder[30][9];
int find_goal(int current_line) {
    for (int i = 0; i < d; i++) {
        if (current_line > 0 && ladder[i][current_line - 1])
            current_line--;
        else if (current_line < n - 1 && ladder[i][current_line])
            current_line++;
    }
    return current_line + 1;
}
int check_if_solvable() {
    int start_position = find_goal(m - 1);
    if (start_position == h) return 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (!ladder[i][j]) {
                ladder[i][j] = 1;
                int new_position = find_goal(m - 1);
                ladder[i][j] = 0;
                if (new_position == h) return i + 1;
            }
        }
    }
    return 1;
}
