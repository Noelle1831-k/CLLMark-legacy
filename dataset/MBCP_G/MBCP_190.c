int countIntegralPoints(int x1, int y1, int x2, int y2) {
    int x_min = x1 < x2 ? x1 : x2;
    int x_max = x1 > x2 ? x1 : x2;
    int y_min = y1 < y2 ? y1 : y2;
    int y_max = y1 > y2 ? y1 : y2;
    int count = 0;
    for (int x = x_min + 1; x < x_max; x++) {
        for (int y = y_min + 1; y < y_max; y++) {
            count++;
        }
    }
    return count;
}