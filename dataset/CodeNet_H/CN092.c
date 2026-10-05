int main(void) {
    int num,i,j,count,k,l;
    char board[1000][1000];
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        count=0;
        for (i=0; i<num; i++) scanf("%s\n",board[i]);
        for (i=0; i<num; i++) {
            for (j=0; j<num; j++) {
                if (board[i][j]=='.') {
                    for (k=0; k+i<num&&k+j<num; k++) {
                        for (l=0; l<=k; l++) {
                            if (board[i+k][j+l]=='*'||board[i+l][j+k]=='*') break;
                        }
                        if (l!=k+1) break;
                    }
                    if (k>count) count=k;
                    j+=k-1;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}