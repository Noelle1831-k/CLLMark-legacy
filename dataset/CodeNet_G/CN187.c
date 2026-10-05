typedef struct {
    int x1, y1, x2, y2;
} Line;
double cross_product(int x1, int y1, int x2, int y2) {
    return x1 * y2 - y1 * x2;
}
int are_lines_parallel(Line l1, Line l2) {
    int dx1 = l1.x2 - l1.x1;
    int dy1 = l1.y2 - l1.y1;
    int dx2 = l2.x2 - l2.x1;
    int dy2 = l2.y2 - l2.y1;
    return cross_product(dx1, dy1, dx2, dy2) == 0;
}
int find_intersection(Line l1, Line l2, double *x, double *y) {
    if (are_lines_parallel(l1, l2)) {
        return 0;
    }
    int A1 = l1.y2 - l1.y1;
    int B1 = l1.x1 - l1.x2;
    int C1 = A1 * l1.x1 + B1 * l1.y1;
    int A2 = l2.y2 - l2.y1;
    int B2 = l2.x1 - l2.x2;
    int C2 = A2 * l2.x1 + B2 * l2.y1;
    int det = A1 * B2 - A2 * B1;
    if (det == 0) {
        return 0;
    } else {
        *x = (B2 * C1 - B1 * C2) / (double)det;
        *y = (A1 * C2 - A2 * C1) / (double)det;
        return 1;
    }
}
double calculate_triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}
void determine_omikuji(double area) {
    if (area >= 1900000) {
        printf("dai-kichi\n");
    } else if (area >= 1000000) {
        printf("chu-kichi\n");
    } else if (area >= 100000) {
        printf("kichi\n");
    } else if (area > 0) {
        printf("syo-kichi\n");
    } else {
        printf("kyo\n");
    }
}
void process_data() {
    Line lines[3];
    while (1) {
        for (int i = 0; i < 3; ++i) {
            scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
        }
        if (lines[0].x1 == 0 && lines[0].y1 == 0 && lines[0].x2 == 0 && lines[0].y2 == 0) {
            break;
        }
        double ix1, iy1, ix2, iy2, ix3, iy3;
        int found1 = find_intersection(lines[0], lines[1], &ix1, &iy1);
        int found2 = find_intersection(lines[1], lines[2], &ix2, &iy2);
        int found3 = find_intersection(lines[2], lines[0], &ix3, &iy3);
        if (!(found1 && found2 && found3)) {
            printf("kyo\n");
            continue;
        }
        if ((ix1 == ix2 && iy1 == iy2) || (ix2 == ix3 && iy2 == iy3) || (ix3 == ix1 && iy3 == iy1)) {
            printf("kyo\n");
            continue;
        }
        double area = calculate_triangle_area(ix1, iy1, ix2, iy2, ix3, iy3);
        determine_omikuji(area);
    }
}
