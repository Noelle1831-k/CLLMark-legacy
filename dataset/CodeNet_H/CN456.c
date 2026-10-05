int main(void) {
  int i, sc, fir = 0, sec = 0, thr = 0, co=2;
  while(co) {
    co--;
    i = 10;
    while(i) {
      i--;
      scanf("%d",&sc);
      if(sc > fir) {
	thr = sec; sec = fir; fir = sc;
      } else if(sc > sec) {
	thr = sec; sec = sc;
      } else if(sc > thr) {
	thr = sc;
      }
    } printf("%d",fir+sec+thr);
    if(co) printf(" ");
    fir=0;sec=0;thr=0;
  }
  puts("");
  return(0);
}