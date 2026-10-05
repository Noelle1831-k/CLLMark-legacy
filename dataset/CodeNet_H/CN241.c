int main() {
int n, i, j, z;
scanf("%d", &n);
int x[n][8];
int y[n][4];
for (i = 0;i < n;i++) {
for (j = 0;j < 8;j++) {
scanf("%d", &x[i][j]);
} } 
scanf("%d", &z);
for (i = 0;i < n;i++) {
for (j = 0;j < 4;j++) {
if (j == 0) {
y[i][0] = x[i][j] * x[i][j + 4];
} else {
y[i][0] = y[i][0] + x[i][j] * -(x[i][j + 4]);
}
} } 
for (i = 0;i < n;i++) {
y[i][1] = x[i][0] * x[i][5] + x[i][1] * x[i][4] + x[i][2] * x[i][7] - x[i][3] * x[i][6];
 }
for (i = 0;i < n;i++) {
y[i][2] = x[i][0] * x[i][6] - x[i][1] * x[i][7] + x[i][2] * x[i][6] + x[i][3] * x[i][5];
 }
for (i = 0;i < n;i++) {
y[i][3] = x[i][0] * x[i][7] + x[i][1] * x[i][6] - x[i][2] * x[i][5] + x[i][3] * x[i][4];
 }
for (i = 0;i < n;i++) {
printf("%d %d %d %d\n", y[i][0], y[i][1], y[i][2], y[i][3]);
}
return 0;
}
