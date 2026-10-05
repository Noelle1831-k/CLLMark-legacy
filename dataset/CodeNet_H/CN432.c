typedef struct {
    int x, y, x2, y2;
} sheet_t;
typedef struct {
    int area, perimeter;
} result_t;
void measure_each_sheet(sheet_t *sheet, int n, result_t *result) {
    int a, p, i, j, w, h, c;
    sheet_t *xsheet, *xs, *s, *t;
    result_t intersection_result;
    xsheet = (sheet_t*)malloc((n-1) * n / 2 * sizeof(sheet_t));
    for (i = 0, a = 0, p = 0, c = 0; i < n; i++) {
        s = &sheet[i];
        w = s->x2 - s->x;
        h = s->y2 - s->y;
        a += w * h;
        p += (w + h) * 2;
        for (j = i + 1; j < n; j++) {
            t = &sheet[j];
            if (s->x2 < t->x || t->x2 < s->x ||
                s->y2 < t->y || t->y2 < s->y) continue;
            xs = &xsheet[c++];
            xs->x = s->x > t->x ? s->x: t->x;
            xs->y = s->y > t->y ? s->y: t->y;
            xs->x2 = s->x2 < t->x2 ? s->x2: t->x2;
            xs->y2 = s->y2 < t->y2 ? s->y2: t->y2;
            w = xs->x2 - xs->x;
            h = xs->y2 - xs->y;
            if (w == 0 || h == 0) {
                p -= (w + h) * 2;
                c--;
            }
        }
    }
    if (c > 0) {
        measure_each_sheet(xsheet, c, &intersection_result);
        a -= intersection_result.area;
        p -= intersection_result.perimeter;
    }
    result->area = a;
    result->perimeter = p;
    free(xsheet);
}
int main (void) {
    int n, r, i;
    sheet_t sheet[10000], *sh;
    result_t result;
    while (scanf("%d%d\n", &n, &r) != EOF && n && r) {
        for (i = 0; i < n; i++) {
            sh = &sheet[i];
            scanf("%d%d%d%d", &(sh->x), &(sh->y), &(sh->x2), &(sh->y2));
        }
        measure_each_sheet(sheet, n, &result);
        printf("%d\n", result.area);
        if (r == 2) printf("%d\n", result.perimeter);
    }
    return 0;
}