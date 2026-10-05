double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int maxOverlap(int n, double centers[][2]) {
    int max_overlap = 0;
    for (int i = 0; i < n; i++) {
        int overlap_count = 0;
        for (int j = 0; j < n; j++) {
            if (distance(centers[i][0], centers[i][1], centers[j][0], centers[j][1]) <= 2.0) {
                overlap_count++;
            }
        }
        if (overlap_count > max_overlap) {
            max_overlap = overlap_count;
        }
    }
    return max_overlap;
}