float calculate_percentage(int part, int total) {
    if (total == 0) return 0.0;
    return ((float)part / total) * 100.0;
}