#define QUE_MAX (100000)
int w, h, n;
int x1[1001], x2[1001], y1[1001], y2[1001];
typedef struct {
    int x, y;
} POINT;
POINT queue[QUE_MAX];
int u[2][1024];
int head, tail;
void enq(POINT t)
{
    queue[tail++ % QUE_MAX] = t;
}
POINT deq(void)
{
    return (queue[head++ % QUE_MAX]);
}
int comp(const void *a, const void *b)
{
    int x, y;
    x = *(int *)a;
    y = *(int *)b;
    return (x - y);
}
int compress(int *x1, int *x2)
{
    int i, j;
    int merge[2048];
    int idx;
    int unq;
    for (i = 0; i < n; i++){
        merge[i] = x1[i];
        merge[n + i] = x2[i];
    }
    qsort(merge, 2 * n, sizeof(int), comp);
    memset(u, 0, sizeof(u));
    unq = 0;
    for (i = 0; i < 2 * n; i++){
        for (j = 0; j < n; j++){
            if (x1[j] == merge[i] && !u[0][j]){
                x1[j] = unq = i;
                u[0][j] = 1;
            }
            if (x2[j] == merge[i] && !u[1][j]){
                x2[j] = unq = i;
                u[1][j] = 1;
            }
        }
    }
    return (unq);
}
int main(void)
{
    int i;
    int x, y;
    int ans;
    static char field[2048][2048];
    POINT temp, add;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while (1){
        scanf("%d%d", &w, &h);
        if (w + h == 0){
            break;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        }
        x1[i] = 0, x2[i] = w, y1[i] = 0, y2[i] = h;
        n++;
        w = compress(x1, x2);
        h = compress(y1, y2);
        memset(field, 0, sizeof(field));
        for (i = 0; i < n - 1; i++){
            for (y = y1[i]; y < y2[i]; y++){
                for (x = x1[i]; x < x2[i]; x++){
                    field[y][x] = 1;
                }
            }
        }
        ans = 0;
        for (y = 0; y < h; y++){
            for (x = 0; x < w; x++){
                if (field[y][x]){
                    continue;
                }
                ans++;
                head = tail = 0;
                temp.y = y;
                temp.x = x;
                field[temp.y][temp.x] = 1;
                enq(temp);
                while (head != tail){
                    temp = deq();
                    for (i = 0; i < 4; i++){
                        add.x = temp.x + dx[i];
                        add.y = temp.y + dy[i];
                        if (0 <= add.x && add.x < w && 0 <= add.y && add.y < h && !field[add.y][add.x]){
                            field[add.y][add.x] = 1;
                            enq(add);
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return (0);
}