int is_rectangle(int a, int b, int c) {
    if (a * a + b * b == c * c) {
        return 1;
    }
    return 0;
}
int is_rhombus(int a, int b, int c) {
    if (a == b) {
        return 1;
    }
    return 0;
}
void count_shapes(const char *input_string, int *rectangle_count, int *rhombus_count) {
    int ai, bi, ci;
    char *s = (char *)input_string;
    *rectangle_count = 0;
    *rhombus_count = 0;
    while (sscanf(s, "%d,%d,%d", &ai, &bi, &ci) == 3) {
        if (is_rectangle(ai, bi, ci)) {
            (*rectangle_count)++;
        }
        if (is_rhombus(ai, bi, ci)) {
            (*rhombus_count)++;
        }
        s = strchr(s, ' ');
        if (s == NULL) break;
        s++;
    }
}