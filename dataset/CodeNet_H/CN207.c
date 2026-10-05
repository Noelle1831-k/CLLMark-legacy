int main(void)
{
    int board[102][102];
    int w, h;
    int xs, ys, xg, yg;
    int c, d, x, y;
    int n;
    int i, j;
    int flag;
    while (1){
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0){
            break;
        }
        scanf("%d%d%d%d", &xs, &ys, &xg, &yg);
        memset(board, 0, sizeof(board));
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            scanf("%d%d%d%d", &c, &d, &x, &y);
            if (d == 0){
                for (j = 0; j < 4; j++){
                    board[y    ][x + j] = 1;
                    board[y + 1][x + j] = 1;
                }
            }
            else {
                for (j = 0; j < 4; j++){
                    board[y + j][x    ] = 1;
                    board[y + j][x + 1] = 1;
                }
            }
        }
        board[ys][xs] = 2;
        while (1){
            flag = 0;
            for (i = 1; i <= h; i++){
                for (j = 1; j <= w; j++){
                    if (board[i][j] == 1){
                        if (board[i][j - 1] == 2){
                            board[i][j] = 2;
                            flag = 1;
                        }
                        else if (board[i][j + 1] == 2){
                            board[i][j] = 2;
                            flag = 1;
                        }
                        else if (board[i + 1][j] == 2){
                            board[i][j] = 2;
                            flag = 1;
                        }
                        else if (board[i - 1][j] == 2){
                            board[i][j] = 2;
                            flag = 1;
                        }
                    }
                }
            }
            if (flag == 0){
                break;
            }
        }
        if (board[yg][xg] == 2){
            printf("OK\n");
        }
        else {
            printf("NG\n");
        }
    }
    return (0);
}