#define N 64
#define MAX(A,B) ((A) < (B) ? (B) : (A))
#define SQ(X) ((X) * (X))
static double x[N];
static double y[N];
static int n;
main()
{
  int i, j;
  for (;;) {
    int rval;
    scanf("%d", &n);
    if (n == 0) break ;
    for (i = 0; i < n; ++i) {
      scanf("%lf,%lf", &x[i], &y[i]);
    }
    rval = 0;
    for (i = 0; i < n; ++i) {
      int tval = 0;
      for (j = 0; j < n; ++j) {
        tval += !!(SQ(x[j] - x[i]) + SQ(y[j] - y[i]) <= 4.);
      }
      rval = MAX(rval, tval);
    }
    printf("%d\n", rval);
  }
  return EXIT_SUCCESS;
}