sx,sy,i,x,y,n;
xx[12],yy[12];
q[9999],t,h,p,ok,c,k;
char *d="22210/.../01";
main()
{
  for(;scanf("%d%d",&sx,&sy),sx;puts(ok?"OK":"NA")){
    for(i=scanf("%d",&n);i<=n;)scanf("%d%d",xx+i++,yy+i);
    for(ok=t=h=0,p=q[t++]=sx*10+sy;t!=h;p=q[h++]){
      c=p/100;
      if(c&&(abs(xx[c]-p/10%10)>1||abs(yy[c]-p%10)>1))continue;
      if(c==n){ok=1;break;}
      for(i=0;i<12;x>=0&x<10&y>=0&x<10?q[t++]=(c+1)*100+x*10+y:0)
        x=p/10%10+d[i]-48,y=p%10+d[11-i++]-48;
    }
  }
}