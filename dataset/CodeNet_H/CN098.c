#define M 100
#define N 100
void max_subarray(int a[M][N], int ans[4]) {
    int left_x, right_x;
    int left_y, right_y;
    int i, j;
    int sum, max;
    int tmp1, tmp2, tmp3;
    int subsum[M][N];
    subsum[0][0] = a[0][0];
    for (i = 1; i < M; i++) {
        subsum[i][0] = subsum[i - 1][0] + a[i][0];
    }
    for (j = 1; j < N; j++) {
        subsum[0][j] = subsum[0][j - 1] + a[0][j];
    }
    for (i = 1; i < M; i++) {
        for (j = 1; j < N; j++) {
            subsum[i][j] = subsum[i - 1][j] + subsum[i][j - 1] - subsum[i - 1][j - 1] + a[i][j];
        }
    }
    max = a[0][0];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    for (left_x = 0; left_x < M; left_x++) {
        for (left_y = 0; left_y < N; left_y++) {
            for (right_x = left_x; right_x < M; right_x++) {
                for (right_y = left_y; right_y < N; right_y++) {
                    if (left_x - 1 < 0) {
                        tmp1 = 0;
                    } else {
                        tmp1 = subsum[left_x - 1][right_y];
                    }
                    if (left_y - 1 < 0) {
                        tmp2 = 0;
                    } else {
                        tmp2 = subsum[right_x][left_y - 1];
                    }
                    if (left_x - 1 < 0 || left_y - 1 < 0) {
                        tmp3 = 0;
                    } else {
                        tmp3 = subsum[left_x - 1][left_y - 1];
                    }
                    sum = subsum[right_x][right_y] - tmp1 - tmp2 + tmp3;
                    if (max < sum) {
                        max = sum;
                        ans[0] = left_x;
                        ans[1] = left_y;
                        ans[2] = right_x - left_x + 1;
                        ans[3] = right_y - left_y + 1;
                    }
                }
            }
        }
    }
}
int main(void){
    int a[M][N] = {0};
    int ans[4]={0};
    int i,j,an=0,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    max_subarray(a, ans);
    for(i=ans[0];i<ans[0]+ans[2];i++){
        for(j=ans[1];j<ans[1]+ans[3];j++){
            an+=a[i][j];
        }
    }
    printf("%d\n", an);
    return 0;
}