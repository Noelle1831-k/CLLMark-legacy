void draw_flag(int W, int H, char c) {
    int centerW = W / 2;
    int centerH = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1) {
                if (j == 0 || j == W - 1) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else if (j == 0 || j == W - 1) {
                printf("|");
            } else if (i == centerH && j == centerW) {
                printf("%c", c);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}