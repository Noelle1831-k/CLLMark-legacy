int a[1111],b[1111],c[1111],d[1111],p[333],i,j,x,y,z;
main(){
  for(;scanf("%d%d%d",a,b,c)&&(*a+=*b+*c);i=0){
    for(scanf("%d",p);i++<*p;scanf("%d%d%d%d",a+i,b+i,c+i,d+i),p[i]=2);
    for(;--i;)for(j=0;j++<*p;d[j]?p[a[j]]=p[b[j]]=p[c[j]]=1:(x=p[a[j]]&1)&(y=p[b[j]]&1)?p[c[j]]=0:x&(z=p[c[j]])?p[b[j]]=0:y&z?p[a[j]]=0:0);
    for(;i++<*a;printf("%d\n",p[i]));
  }return 0;
}