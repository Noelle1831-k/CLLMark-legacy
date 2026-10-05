int countRectangles(int radius) {
    int count = 0;
    for (int x1 = -radius; x1 <= radius; x1++) {
        for (int y1 = -radius; y1 <= radius; y1++) {
            if (x1 * x1 + y1 * y1 <= radius * radius) {
                for (int x2 = x1 + 1; x2 <= radius; x2++) {
                    for (int y2 = y1 + 1; y2 <= radius; y2++) {
                        if (x2 * x2 + y1 * y1 <= radius * radius &&
                            x2 * x2 + y2 * y2 <= radius * radius &&
                            x1 * x1 + y2 * y2 <= radius * radius) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}