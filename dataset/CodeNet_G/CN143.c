int is_inside_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    int d1 = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    int d2 = (x - x2) * (y3 - y2) - (y - y2) * (x3 - x2);
    int d3 = (x - x3) * (y1 - y3) - (y - y3) * (x1 - x3);
    int has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    int has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}
void process_queries(int n, int queries[][10]) {
    for (int i = 0; i < n; ++i) {
        int *q = queries[i];
        int triangle_points[6] = {q[0], q[1], q[2], q[3], q[4], q[5]};
        int k_position[2] = {q[6], q[7]};
        int s_position[2] = {q[8], q[9]};
        int k_inside = is_inside_triangle(triangle_points[0], triangle_points[1],
                                          triangle_points[2], triangle_points[3],
                                          triangle_points[4], triangle_points[5],
                                          k_position[0], k_position[1]);
        int s_inside = is_inside_triangle(triangle_points[0], triangle_points[1],
                                          triangle_points[2], triangle_points[3],
                                          triangle_points[4], triangle_points[5],
                                          s_position[0], s_position[1]);
        if (k_inside != s_inside) {
            printf("OK\n");
        } else {
            printf("NG\n");
        }
    }
}