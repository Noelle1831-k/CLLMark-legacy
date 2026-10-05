typedef struct {
    int x, y, brightness;
} Star;
int compareBrightness(const void *a, const void *b) {
    return ((Star *)a)->brightness - ((Star *)b)->brightness;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
long long calculateArea(Star stars[], int start, int end) {
    if (start >= end) return 0;
    int minX = stars[start].x;
    int maxX = stars[start].x;
    int minY = stars[start].y;
    int maxY = stars[start].y;
    for (int i = start; i <= end; i++) {
        minX = min(minX, stars[i].x);
        maxX = max(maxX, stars[i].x);
        minY = min(minY, stars[i].y);
        maxY = max(maxY, stars[i].y);
    }
    return (long long)(maxX - minX) * (maxY - minY);
}
int main() {
    int N, d;
    scanf("%d %d", &N, &d);
    Star stars[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &stars[i].x, &stars[i].y, &stars[i].brightness);
    }
    qsort(stars, N, sizeof(Star), compareBrightness);
    long long maxArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N && stars[j].brightness - stars[i].brightness <= d; j++) {
            long long currentArea = calculateArea(stars, i, j);
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }
        }
    }
    printf("%lld\n", maxArea);
    return 0;
}