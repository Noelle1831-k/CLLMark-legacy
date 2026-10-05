#define MAX_SIZE 20
#define MAX_PIECES 10
typedef struct {
    int h, w;
    char data[MAX_SIZE][MAX_SIZE];
} Piece;
int fits(char grid[MAX_SIZE][MAX_SIZE], int H, int W, Piece *pieces, int num_pieces, int *used, int num_used) {
    char temp[MAX_SIZE][MAX_SIZE];
    memcpy(temp, grid, sizeof(temp));
    for (int i = 0; i < num_used; ++i) {
        int idx = used[i] - 1;
        for (int rotation = 0; rotation < 4; ++rotation) {
            Piece *p = &pieces[idx];
            int ph = p->h, pw = p->w;
            for (int i = 0; i < H - ph + 1; ++i) {
                for (int j = 0; j < W - pw + 1; ++j) {
                    int fits = 1;
                    for (int x = 0; x < ph; ++x) {
                        for (int y = 0; y < pw; ++y) {
                            if (p->data[x][y] == '#' && temp[i + x][j + y] == '#') {
                                fits = 0;
                                break;
                            }
                        }
                        if (!fits) break;
                    }
                    if (fits) {
                        for (int x = 0; x < ph; ++x)
                            for (int y = 0; y < pw; ++y)
                                if (p->data[x][y] == '#')
                                    temp[i + x][j + y] = '#';
                        goto placement_done;
                    }
                }
            }
            placement_done:
            if (rotation < 3) {
                Piece rotated = *p;
                for (int x = 0; x < ph; ++x)
                    for (int y = 0; y < pw; ++y)
                        rotated.data[y][ph - x - 1] = p->data[x][y];
                pieces[idx] = rotated;
            } else {
                memset(&pieces[idx], 0, sizeof(Piece));
            }
        }
    }
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (temp[i][j] == '.')
                return 0;
    return 1;
}
int main() {
    int H, W;
    char grid[MAX_SIZE][MAX_SIZE];
    Piece pieces[MAX_PIECES];
    int p, num_pieces, num_used, player[MAX_PIECES];
    while (scanf("%d %d", &H, &W) == 2 && H && W) {
        for (int i = 0; i < H; ++i)
            scanf("%s", grid[i]);
        scanf("%d", &num_pieces);
        for (int i = 0; i < num_pieces; ++i) {
            scanf("%d %d", &pieces[i].h, &pieces[i].w);
            for (int j = 0; j < pieces[i].h; ++j)
                scanf("%s", pieces[i].data[j]);
        }
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d", &num_used);
            for (int j = 0; j < num_used; ++j)
                scanf("%d", &player[j]);
            if (fits(grid, H, W, pieces, num_pieces, player, num_used))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
