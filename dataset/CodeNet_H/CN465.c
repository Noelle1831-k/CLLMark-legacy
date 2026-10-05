int room[2][500][500];
char v[500][500];
int num, count;
int r;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int which, int ty, int tx, int level, int y, int x)
{
    int i;
    int my, mx;
    v[ty][tx] = 1;
    count++;
    if (num + count >= r){
        return;
    }
    for (i = 0; i < 4; i++){
        my = ty + dy[i];
        mx = tx + dx[i];
        if (0 <= mx && mx < x && 0 <= my && my < y && v[my][mx] == 0 && room[which][my][mx] <= level){
            dfs(which, my, mx, level, y, x);
        }
    }
}
int main(void)
{
    int w1, h1, sx1, sy1;
    int w2, h2, sx2, sy2;
    int i, j;
    int left, right, center;
    int ileft, iright, icenter;
    int res;
    while (1){
        scanf("%d", &r);
        if (r == 0){
            break;
        }
        scanf("%d%d%d%d", &w1, &h1, &sx1, &sy1);
        sx1--;
        sy1--;
        for (i = 0; i < h1; i++){
            for (j = 0; j < w1; j++){
                scanf("%d", &room[0][i][j]);
            }
        }
        scanf("%d%d%d%d", &w2, &h2, &sx2, &sy2);
        sx2--;
        sy2--;
        for (i = 0; i < h2; i++){
            for (j = 0; j < w2; j++){
                scanf("%d", &room[1][i][j]);
            }
        }
        left = 0;
        right = 100000000;
        res = 999999999;
        while (left != right){
            center = (left + right) / 2;
            num = count = 0;
            memset(v, 0, sizeof(v));
            if (center > 0){
                dfs(0, sy1, sx1, center, h1, w1);
            }
            num += count;
            ileft = 0;
            iright = 100000000;
            while (ileft < iright){
                icenter = (ileft + iright) / 2;
                count = 0;
                memset(v, 0, sizeof(v));
                if (center > 0){
                    dfs(1, sy2, sx2, icenter, h2, w2);
                }
                if (num + count >= r){
                    iright = icenter;
                }
                else {
                    ileft = icenter + 1;
                }
            }
            if (ileft > iright){
                ileft = iright = 1000000000;
            }
            if (ileft + center < res){
                res = ileft + center;
                right = center;
            }
            else {
                left = center + 1;
            }
        }
        printf("%d\n", res);
    }
    return (0);
}