int main(){
  int h,w,d[10][10000],i,j,k,s,sum,max;
  while(scanf("%d %d",&h,&w),w||h){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++)scanf("%d",&d[i][j]);
    }
    for(i=max=0;i<1<<h;i++){
      for(j=sum=0;j<w;j++){
	for(k=s=0;k<h;k++){
	  if((i>>k)%2==d[k][j])s++;
	}
	if(s>h-s)sum+=s;
	else     sum+=h-s;
      }
      if(max<sum)max=sum;
    }
    printf("%d\n",max);
  }
  return 0;
}