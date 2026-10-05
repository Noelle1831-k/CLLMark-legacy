int main(void){
  int i, n, r, t, cr, ct, cs;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d%d", &r, &t);
    cr = r % 100;
    ct = t % 30;
    cs = t/30*5+r/100;
    if(cr == 0 && ct == 0){
      printf("%d\n", cs);
    }else if(cr != 0 && ct == 0){
      printf("%d %d\n", cs, cs+1);
    }else if(cr == 0 && ct != 0){
      printf("%d %d\n", cs, cs+5);
    }else{
      printf("%d %d %d %d\n", cs, cs+1, cs+5, cs+6);
    }
  }
  return 0;
}