float clamp(float value, float min, float max) {
    if (value < min) return min;
    if (max < value) return max;
    return value;
}