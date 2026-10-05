#define MAX_N   (100)
#define MAX_T   (10)
typedef struct _pt_t {
  double x, y;
} pt_t;
typedef struct _wind_t {
  int w, a;
} wind_t;
static pt_t houses[MAX_N];
static wind_t winds[MAX_N];
static pt_t ume[MAX_T], momo[MAX_T], sakura[MAX_T];
static pt_t origin = {0, 0};
static int max_houses[MAX_N];
double dist2(pt_t *p0, pt_t *p1) {
  double dx = p1->x - p0->x;
  double dy = p1->y - p0->y;
  return (dx * dx + dy * dy);
}
double o_prod(pt_t *v0, pt_t *v1) {
  return (v0->x * v1->y - v0->y * v1->x);
}
int deg_inside(pt_t *p0, pt_t *p1, double d0, double d1) {
  double rad0, rad1;
  pt_t dv0, dv1, pv;
  rad0 = d0 * M_PI / 180;
  rad1 = d1 * M_PI / 180;
  dv0.x = cos(rad0);
  dv0.y = sin(rad0);
  dv1.x = cos(rad1);
  dv1.y = sin(rad1);
  pv.x = p1->x - p0->x;
  pv.y = p1->y - p0->y;
  return (o_prod(&dv0, &pv) >= 0.0 && o_prod(&dv1, &pv) <= 0.0);
}
int reach(pt_t *src, pt_t *h, wind_t *w, int d) {
  return
    (dist2(src, h) <= (w->a * w->a) &&
     deg_inside(src, h, w->w - 0.5 * d, w->w + 0.5 * d));
}
int main(int argc, char **argv) {
  int i, j, k, hn, rn, un, mn, sn, du, dm, ds;
  int days, max_days, max_hn;
  pt_t *hpt, *upt, *mpt, *spt;
  wind_t *wpt;
  for(;;) {
    scanf("%d%d", &hn, &rn);
    if (hn == 0 && rn == 0) break;
    for (i = 0; i < hn; i++)
      scanf("%lf%lf", &(houses[i].x), &(houses[i].y));
    scanf("%d%d%d%d%d%d", &un, &mn, &sn, &du, &dm, &ds);
    for (i = 0; i < un; i++)
      scanf("%lf%lf", &(ume[i].x), &(ume[i].y));
    for (i = 0; i < mn; i++)
      scanf("%lf%lf", &(momo[i].x), &(momo[i].y));
    for (i = 0; i < sn; i++)
      scanf("%lf%lf", &(sakura[i].x), &(sakura[i].y));
    for (i = 0; i < rn; i++)
      scanf("%d%d", &(winds[i].w), &(winds[i].a));
    max_days = 0;
    max_hn = 0;
    for (i = 0; i < hn; i++) {
      hpt = &(houses[i]);
      days = 0;
      for (j = 0; j < rn; j++) {
        wpt = &(winds[j]);
        if (reach(&origin, hpt, wpt, du)) {
          int ok = 1;
          for (k = 0; k < un; k++)
            if (reach(&(ume[k]), hpt, wpt, du)) {
              ok = 0;
              break;
            }
          if (! ok) break;
          for (k = 0; k < mn; k++)
            if (reach(&(momo[k]), hpt, wpt, dm)) {
              ok = 0;
              break;
            }
          if (! ok) break;
          for (k = 0; k < sn; k++)
            if (reach(&(sakura[k]), hpt, wpt, ds)) {
              ok = 0;
              break;
            }
          if (! ok) break;
          days++;
        }
      }
      if (max_days < days) {
        max_days = days;
        max_hn = 1;
        max_houses[0] = i + 1;
      }
      else if (max_days == days) {
        max_houses[max_hn++] = i + 1;
      }
    }
    if (max_days == 0)
      puts("NA");
    else {
      for (i = 0; i < max_hn; i++) {
        if (i > 0) putchar(' ');
        printf("%d", max_houses[i]);
      }
      putchar('\n');
    }
  }
  return 0;
}