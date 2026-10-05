typedef struct {
    int x1, y1, x2, y2;
} Segment;
int check_overlap(Segment a, Segment b) {
    if (a.y1 == a.y2 && b.y1 == b.y2) {
        return (a.y1 == b.y1) && ((a.x1 <= b.x1 && b.x1 <= a.x2) || (a.x1 <= b.x2 && b.x2 <= a.x2) || (b.x1 <= a.x1 && a.x1 <= b.x2) || (b.x1 <= a.x2 && a.x2 <= b.x2));
    } else if (a.x1 == a.x2 && b.x1 == b.x2) {
        return (a.x1 == b.x1) && ((a.y1 <= b.y1 && b.y1 <= a.y2) || (a.y1 <= b.y2 && b.y2 <= a.y2) || (b.y1 <= a.y1 && a.y1 <= b.y2) || (b.y1 <= a.y2 && a.y2 <= b.y2));
    }
    return 0;
}
int main() {
    int N;
    scanf("%d", &N);
    Segment segments[N];
    int results[N];
    for (int i = 0; i < N; i++) {
        int px, py, qx, qy;
        scanf("%d %d %d %d", &px, &py, &qx, &qy);
        if (px > qx || py > qy) {
            int temp;
            temp = px; px = qx; qx = temp;
            temp = py; py = qy; qy = temp;
        }
        segments[i] = (Segment){px, py, qx, qy};
    }
    for (int i = 0; i < N; i++) {
        int add = 1;
        for (int j = 0; j < i; j++) {
            if (check_overlap(segments[i], segments[j])) {
                add = 0;
                break;
            }
        }
        results[i] = add;
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}