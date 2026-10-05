#define N 12
#define GETDATA(X,Y) ((X) >= 0 && (Y) >= 0 && (X) < 10 && (Y) < 10 ? d[X][Y] : 0)
static int d[10][10];
static int n;
static int st[N][3];
static jmp_buf e1;
static void try(int k) {
  int i, j;
  if (k == n) {
    for (i = 0; i < 10; ++i)
    for (j = 0; j < 10; ++j) {
      if (d[i][j]) {
        return ;
      }
    }
    longjmp(e1, 1);
  }
  for (i = 0; i < 10; ++i)
  for (j = 0; j < 10; ++j) {
    if (!GETDATA(i, j) || !GETDATA(i - 1, j) || !GETDATA(i + 1, j) || !GETDATA(i, j - 1) || !GETDATA(i, j + 1))
      continue ;
    --d[i][j]; --d[i - 1][j]; --d[i + 1][j]; --d[i][j - 1]; --d[i][j + 1];
    st[k][0] = j;
    st[k][1] = i;
    st[k][2] = 1;
    try(k + 1);
    ++d[i][j]; ++d[i - 1][j]; ++d[i + 1][j]; ++d[i][j - 1]; ++d[i][j + 1];
    if (!GETDATA(i - 1, j - 1) || !GETDATA(i - 1, j + 1) || !GETDATA(i + 1, j - 1) || !GETDATA(i + 1, j + 1))
      continue ;
    --d[i][j]; --d[i - 1][j]; --d[i + 1][j]; --d[i][j - 1]; --d[i][j + 1];
    --d[i - 1][j - 1]; --d[i - 1][j + 1]; --d[i + 1][j - 1]; --d[i + 1][j + 1];
    st[k][0] = j;
    st[k][1] = i;
    st[k][2] = 2;
    try(k + 1);
    ++d[i - 1][j - 1]; ++d[i - 1][j + 1]; ++d[i + 1][j - 1]; ++d[i + 1][j + 1];
    ++d[i][j]; ++d[i - 1][j]; ++d[i + 1][j]; ++d[i][j - 1]; ++d[i][j + 1];
    if (!GETDATA(i - 2, j) || !GETDATA(i + 2, j) || !GETDATA(i, j - 2) || !GETDATA(i, j + 2))
      continue ;
    --d[i][j]; --d[i - 1][j]; --d[i + 1][j]; --d[i][j - 1]; --d[i][j + 1];
    --d[i - 1][j - 1]; --d[i - 1][j + 1]; --d[i + 1][j - 1]; --d[i + 1][j + 1];
    --d[i - 2][j]; --d[i + 2][j]; --d[i][j - 2]; --d[i][j + 2];
    st[k][0] = j;
    st[k][1] = i;
    st[k][2] = 3;
    try(k + 1);
    ++d[i - 2][j]; ++d[i + 2][j]; ++d[i][j - 2]; ++d[i][j + 2];
    ++d[i - 1][j - 1]; ++d[i - 1][j + 1]; ++d[i + 1][j - 1]; ++d[i + 1][j + 1];
    ++d[i][j]; ++d[i - 1][j]; ++d[i + 1][j]; ++d[i][j - 1]; ++d[i][j + 1];
  }
  try(k + 1);
}
int main(int argc, char *argv[]) {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < 10; ++i)
  for (j = 0; j < 10; ++j) {
    scanf("%d", &d[i][j]);
  }
  if (setjmp(e1) == 0) {
    try(0);
  } else {
    for (i = 0; i < n; ++i) {
      printf("%d %d %d\n", st[i][0], st[i][1], st[i][2]);
    }
  }
  return EXIT_SUCCESS;
}