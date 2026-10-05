#define MAX 101
int visited[MAX][MAX];
char room[MAX][MAX];
int H, W;
void move(int *x, int *y) {
    switch (room[*y][*x]) {
        case '>': (*x)++; break;
        case '<': (*x)--; break;
        case '^': (*y)--; break;
        case 'v': (*y)++; break;
    }
}
int simulate() {
    int x = 0, y = 0;
    memset(visited, 0, sizeof(visited));
    while (1) {
        if (visited[y][x]) return 1;
        if (room[y][x] == '.') break;
        visited[y][x] = 1;
        move(&x, &y);
    }
    printf("%d %d\n", x, y);
    return 0;
}
int main() {
    while (scanf("%d %d", &H, &W), H || W) {
        for (int i = 0; i < H; i++)
            scanf("%s", room[i]);
        if (simulate()) printf("LOOP\n");
    }
    return 0;
}
