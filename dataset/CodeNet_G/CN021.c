float get_slope(float x1, float y1, float x2, float y2) {
    if (x2 - x1 == 0) {
        return (y2 > y1) ? INFINITY : -INFINITY;
    }
    return (y2 - y1) / (x2 - x1);
}
void are_lines_parallel(int n, float datasets[][8], char results[][4]) {
    for (int i = 0; i < n; ++i) {
        float x1 = datasets[i][0], y1 = datasets[i][1];
        float x2 = datasets[i][2], y2 = datasets[i][3];
        float x3 = datasets[i][4], y3 = datasets[i][5];
        float x4 = datasets[i][6], y4 = datasets[i][7];
        float slopeAB = get_slope(x1, y1, x2, y2);
        float slopeCD = get_slope(x3, y3, x4, y4);
        if (slopeAB == slopeCD) {
            strcpy(results[i], "YES");
        } else {
            strcpy(results[i], "NO");
        }
    }
}