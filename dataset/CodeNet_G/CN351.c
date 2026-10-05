typedef struct Building {
    int x;
    int w;
    int h;
} Building;
double calculate_cover_height(double yc, double R, int x, int w, int h) {
    if (yc <= h) return R;
    double dx = sqrt(R * R - (h - yc + R) * (h - yc + R));
    double left = x - dx;
    double right = x + w + dx;
    double cover_height = R - sqrt(R * R - dx * dx);
    return cover_height;
}
double find_max_yc(Building buildings[], int N, double R) {
    double low = 0.0, high = 2 * R, mid;
    const double eps = 1e-7;
    while (high - low > eps) {
        mid = (low + high) / 2.0;
        double cover_area = 0.0;
        for (int i = 0; i < N; ++i) {
            double cover_height = calculate_cover_height(mid, R, buildings[i].x, buildings[i].w, buildings[i].h);
            cover_area += cover_height * buildings[i].w;
        }
        if (cover_area >= M_PI * R * R / 2.0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (low + high) / 2.0;
}