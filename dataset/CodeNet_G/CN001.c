void top_three_hills(int heights[]) {
    int first = 0, second = 0, third = 0;
    for (int i = 0; i < 10; i++) {
        if (heights[i] > first) {
            third = second;
            second = first;
            first = heights[i];
        } else if (heights[i] > second) {
            third = second;
            second = heights[i];
        } else if (heights[i] > third) {
            third = heights[i];
        }
    }
    printf("%d %d %d\n", first, second, third);
}
