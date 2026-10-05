int main(void)
{
  double x=0,y=0;
  double a,b;
  double tmp=0;
  double o=90;
  while(scanf("%lf,%lf",&a,&b),a!=0 && b!=0){
    double e=(o-tmp)*M_PI/180;
    x+=a*cos( e );
    y+=a*sin( e );
    o-=tmp;
    tmp=b;
  }
  printf("%d\n%d\n",(int)x,(int)y);
  return 0;
}