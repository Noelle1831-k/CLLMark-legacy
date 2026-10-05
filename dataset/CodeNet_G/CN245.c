typedef struct {
    int x, y;
    int discount;
    int start, end;
    int product_id;
} ProductInfo;
typedef struct {
    int x, y;
} Point;
int max_discount;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char store[20][20];
int visited[20][20][1 << 10];
void dfs(int x, int y, int X, int Y, int current_time, int discounts, int bitmask, ProductInfo products[], int num_products) {
    max_discount = max_discount > discounts ? max_discount : discounts;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx < 0 || nx >= X || ny < 0 || ny >= Y || store[ny][nx] == '#') continue;
        if (!visited[ny][nx][bitmask] || (visited[ny][nx][bitmask] > current_time + 1)) {
            visited[ny][nx][bitmask] = current_time + 1;
            dfs(nx, ny, X, Y, current_time + 1, discounts, bitmask, products, num_products);
        }
    }
    if (store[y][x] >= '0' && store[y][x] <= '9') {
        int g = store[y][x] - '0';
        if (!(bitmask & (1 << g))) {
            for (int i = 0; i < num_products; i++) {
                if (products[i].product_id == g) {
                    if (products[i].start <= current_time && current_time < products[i].end) {
                        int new_bitmask = bitmask | (1 << g);
                        if (!visited[y][x][new_bitmask] || visited[y][x][new_bitmask] > current_time) {
                            visited[y][x][new_bitmask] = current_time;
                            dfs(x, y, X, Y, current_time, discounts + products[i].discount, new_bitmask, products, num_products);
                        }
                    }
                    break;
                }
            }
        }
    }
}
int get_max_discount(int X, int Y, char map[Y][X], ProductInfo products[], int num_products) {
    int start_x, start_y;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            store[i][j] = map[i][j];
            if (store[i][j] == 'P') {
                start_x = j;
                start_y = i;
                store[i][j] = '.';
            }
        }
    }
    max_discount = 0;
    memset(visited, 0, sizeof(visited));
    dfs(start_x, start_y, X, Y, 0, 0, 0, products, num_products);
    return max_discount;
}