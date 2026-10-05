int main(){
  int min,y,t1,t2,g;
  int a,b,p;
  while(1){
    scanf("%d",&min);
    if(min==0)break;
    scanf("%d %d %d %d",&y,&t1,&t2,&g);
    a=y/t1;
    b=0;
    if(a>g){
      a=g;
    }
    y-=a*t1;
    b=y/t2;
    y-=b*t2;
    while(min>a+b){
      if(a==0)break;
      a--;
      y+=t1;
      p=y/t2;
      y-=p*t2;
      b+=p;
    }
    if(a==0)printf("NA\n");
    else    printf("%d %d\n",a,b);
  }
  return 0;
}