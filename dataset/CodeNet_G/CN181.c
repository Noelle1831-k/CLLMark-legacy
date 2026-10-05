int minWidth(int m, int n, int w[]) {
    int left = 0, right = 1500000, result = 1500000;
    while (left <= right) {
        int mid = (left + right) / 2;
        int shelves = 1, current_width = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] > mid) {
                shelves = m + 1;
                break;
            }
            if (current_width + w[i] > mid) {
                shelves++;
                current_width = w[i];
                if (shelves > m) break;
            } else {
                current_width += w[i];
            }
        }
        if (shelves <= m) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}