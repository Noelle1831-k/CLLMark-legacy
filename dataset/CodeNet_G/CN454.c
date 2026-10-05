#define MAX_N 1000
typedef struct {
    int x1, y1, x2, y2;
} Tape;
Tape tapes[MAX_N];
int x_coords[2 * MAX_N + 2], y_coords[2 * MAX_N + 2];
int x_count, y_count;
int compress(int coords[], int count) {
    qsort(coords, count, sizeof(int), (int (*)(const void *, const void *)) (int (*)(const int *, const int *)) {
        return *((const int *) a) - *((const int *) b);
    });
    int compressed_count = 1;
    for (int i = 1; i < count; ++i) {
        if (coords[i] != coords[i - 1]) {
            coords[compressed_count++] = coords[i];
        }
    }
    return compressed_count;
}
int find_index(int value, int array[], int size) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
void dfs(int **grid, int x, int y, int x_max, int y_max, int color) {
    if (x < 0 || y < 0 || x >= x_max || y >= y_max || grid[x][y] != 0)
        return;
    grid[x][y] = color;
    dfs(grid, x + 1, y, x_max, y_max, color);
    dfs(grid, x - 1, y, x_max, y_max, color);
    dfs(grid, x, y + 1, x_max, y_max, color);
    dfs(grid, x, y - 1, x_max, y_max, color);
}
int main() {
    int w, h, n;
    while (scanf("%d %d", &w, &h) && (w || h)) {
        scanf("%d", &n);
        x_count = y_count = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &tapes[i].x1, &tapes[i].y1, &tapes[i].x2, &tapes[i].y2);
            x_coords[x_count++] = tapes[i].x1;
            x_coords[x_count++] = tapes[i].x2;
            y_coords[y_count++] = tapes[i].y1;
            y_coords[y_count++] = tapes[i].y2;
        }
        x_coords[x_count++] = 0;
        x_coords[x_count++] = w;
        y_coords[y_count++] = 0;
        y_coords[y_count++] = h;
        x_count = compress(x_coords, x_count);
        y_count = compress(y_coords, y_count);
        int **grid = (int **) malloc(x_count * sizeof(int *));
        for (int i = 0; i < x_count; ++i) {
            grid[i] = (int *) calloc(y_count, sizeof(int));
        }
        for (int i = 0; i < n; ++i) {
            int x1_idx = find_index(tapes[i].x1, x_coords, x_count);
            int x2_idx = find_index(tapes[i].x2, x_coords, x_count);
            int y1_idx = find_index(tapes[i].y1, y_coords, y_count);
            int y2_idx = find_index(tapes[i].y2, y_coords, y_count);
            for (int x = x1_idx; x < x2_idx; ++x) {
                for (int y = y1_idx; y < y2_idx; ++y) {
                    grid[x][y] = -1;
                }
            }
        }
        int colors = 0;
        for (int x = 0; x < x_count - 1; ++x) {
            for (int y = 0; y < y_count - 1; ++y) {
                if (grid[x][y] == 0) {
                    dfs(grid, x, y, x_count, y_count, ++colors);
                }
            }
        }
        printf("%d\n", colors);
        for (int i = 0; i < x_count; ++i) {
            free(grid[i]);
        }
        free(grid);
    }
    return 0;
}