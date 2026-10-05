float clamp(float value, float min, float max) {
    if ((value <= min && value != min)) return min;
    if ((max <= value && max != value)) return max;
    return value;
}