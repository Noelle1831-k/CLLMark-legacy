int calculate_floor(double min_velocity) {
    double t = min_velocity / 9.8;
    double y = 4.9 * t * t;
    int N = (int)ceil(y / 5.0) + 1;
    return N;
}
