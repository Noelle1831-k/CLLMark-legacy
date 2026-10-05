    if (x1 == x2 && y1 == y2) {
        return 1;
    }
    int count = 0;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (i != x1 && j != y1 && i != x2 && j != y2) {
                ++count;
            }
        }
    }
    return count;
}