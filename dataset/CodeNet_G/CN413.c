int nonOverlappingArea(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    int area1 = w1 * h1;
    int area2 = w2 * h2;
    int overlapX = 0;
    int overlapY = 0;
    int x1_end = x1 + w1;
    int y1_end = y1 + h1;
    int x2_end = x2 + w2;
    int y2_end = y2 + h2;
    int overlap_width = (x1_end > x2_end ? x2_end : x1_end) - (x1 > x2 ? x1 : x2);
    int overlap_height = (y1_end > y2_end ? y2_end : y1_end) - (y1 > y2 ? y1 : y2);
    if (overlap_width > 0 && overlap_height > 0) {
        overlapX = overlap_width;
        overlapY = overlap_height;
    }
    int overlapArea = overlapX * overlapY;
    int result = area1 + area2 - overlapArea;
    return result;
}