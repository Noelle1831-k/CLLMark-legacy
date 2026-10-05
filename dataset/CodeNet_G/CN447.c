void find_translation(int m, int constellation[][2], int n, int photo[][2], int *result_x, int *result_y) {
    for (int i = 0; i < n; i++) {
        int dx = photo[i][0] - constellation[0][0];
        int dy = photo[i][1] - constellation[0][1];
        int found = 1;
        for (int j = 1; j < m; j++) {
            int match = 0;
            for (int k = 0; k < n; k++) {
                if (photo[k][0] == constellation[j][0] + dx && photo[k][1] == constellation[j][1] + dy) {
                    match = 1;
                    break;
                }
            }
            if (!match) {
                found = 0;
                break;
            }
        }
        if (found) {
            *result_x = dx;
            *result_y = dy;
            return;
        }
    }
}