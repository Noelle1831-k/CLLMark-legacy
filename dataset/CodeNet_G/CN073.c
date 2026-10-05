double calculate_surface_area(int x, int h) {
    double slant_height = sqrt(h * h + (x / 2.0) * (x / 2.0));
    double side_area = 2 * x * slant_height;
    double base_area = x * x;
    return side_area + base_area;
}