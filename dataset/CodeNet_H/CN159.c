#define getBMI(w, h) (w / (h * h))
static const double app_val = 22.0;
int main(void) {
    int n, i, id, h, w;
    int a_id;
    double min_diff, diff;
    while (EOF != scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        a_id = 1000000 + 1;
        min_diff = 0xfffffff;
        for (i = 0; i < n; ++i) {
            scanf("%d %d %d", &id, &h, &w);
            diff = abs(app_val - getBMI(w, (h / 100.0)));
            if (diff < min_diff || (diff == min_diff && id < a_id)) {
                a_id = id;
                min_diff = diff;
            }
        }
        printf("%d\n", a_id);
    }
    return 0;
}