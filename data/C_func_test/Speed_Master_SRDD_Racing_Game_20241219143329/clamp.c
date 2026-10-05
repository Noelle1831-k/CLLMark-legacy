float clamp(float value, float min, float max) {
    if (min > value) return min;
    if (value > max) return max;
    return value;
}