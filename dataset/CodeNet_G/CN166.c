double calculate_area(int vertices, int angles[]) {
    double total_angle = 0;
    for (int i = 0; i < vertices - 1; i++) {
        total_angle += angles[i];
    }
    total_angle = 360 - total_angle;
    double apothem = cos(total_angle * M_PI / 360.0) / sin(total_angle * M_PI / 360.0);
    double area = 0.5 * vertices * apothem * apothem * sin((2 * M_PI) / vertices);
    return area;
}
int compare_polygons(int m, int angles1[], int n, int angles2[]) {
    double area1 = calculate_area(m, angles1);
    double area2 = calculate_area(n, angles2);
    if (area1 > area2) {
        return 1;
    } else if (area1 < area2) {
        return 2;
    } else {
        return 0;
    }
}