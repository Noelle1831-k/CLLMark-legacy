int cmp(const char *a, const char *b) { return *a - *b; }
int rcmp(const char *a, const char *b) { return *b - *a; }
int main() {
  char num[9] = {};
  int i, j, n;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    int j, min, max;
    for (j = 0; j < 8; j++) {
      scanf("%c", num+j);
    }
    scanf("\n");
    num[8] = 0;
    sscanf(num, "%d", &min);
    sscanf(num, "%d", &max);
    printf("%d\n", max - min);
  }
  return 0;
}