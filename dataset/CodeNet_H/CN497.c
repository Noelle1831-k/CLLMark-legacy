#define max(x,y) ((x) > (y) ? (x) : (y))
int n, m;
int nails[5002][5002];
int ans, i, j;
int main(){
  scanf("%d%d", &n, &m);
  for(i = 0;i < m;i++){
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);
    nails[a - 1][b - 1] = max(nails[a - 1][b - 1], x + 1);
  }
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      if(nails[i][j] == 0)continue;
      ans++;
      nails[i + 1][j] = max(nails[i + 1][j], nails[i][j] - 1);
      nails[i + 1][j + 1] = max(nails[i + 1][j + 1], nails[i][j] - 1);
    }
  }
  printf("%d\n", ans);
}