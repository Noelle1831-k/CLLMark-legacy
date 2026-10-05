float calculate_elevation_difference(float heights[], int count) {
    float max = heights[0];
    float min = heights[0];
    for (int i = 1; i < count; i++) {
        if (heights[i] > max) {
            max = heights[i];
        }
        if (heights[i] < min) {
            min = heights[i];
        }
    }
    return max - min;
}