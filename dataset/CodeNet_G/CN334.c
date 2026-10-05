#define MAX_TRIANGLES 1000
typedef struct {
    int v1;
    int v2;
    int v3;
} Triangle;
int compareTriangles(const void *a, const void *b) {
    Triangle *t1 = (Triangle *)a;
    Triangle *t2 = (Triangle *)b;
    if (t1->v1 != t2->v1) return t1->v1 - t2->v1;
    if (t1->v2 != t2->v2) return t1->v2 - t2->v2;
    return t1->v3 - t2->v3;
}
void assignSortedVertices(Triangle *tri, int a, int b, int c) {
    if (a > b) { int tmp = a; a = b; b = tmp; }
    if (b > c) { int tmp = b; b = c; c = tmp; }
    if (a > b) { int tmp = a; a = b; b = tmp; }
    tri->v1 = a;
    tri->v2 = b;
    tri->v3 = c;
}
int countDuplicateTriangles(Triangle triangles[], int n) {
    for (int i = 0; i < n; ++i) {
        assignSortedVertices(&triangles[i], triangles[i].v1, triangles[i].v2, triangles[i].v3);
    }
    qsort(triangles, n, sizeof(Triangle), compareTriangles);
    int duplicates = 0;
    for (int i = 1; i < n; ++i) {
        if (compareTriangles(&triangles[i], &triangles[i - 1]) == 0) {
            duplicates++;
        }
    }
    return duplicates;
}