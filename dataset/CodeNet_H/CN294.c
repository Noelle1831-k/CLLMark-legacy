int main(){
  int n, m, p, min, x, y, sum=0, cnt=0, i;
  int d[10000][2]={};
  scanf("%d %d %d", &n, &m, &p);
  for(i=0;i<m;i++) scanf("%d", &d[i][0]);
  while(1){
    min=50000;
    for(i=0;i<m;i++){
      if(d[i][1]==0){
	if(n-d[i][0]+p<d[i][0]-p){
	  x=n-d[i][0]+p;
	  if(x<0) x*=-1;
	}else{
	  x=d[i][0]-p;
	  if(x<0) x*=-1;
	}
	if(min>x){
	  min=x;
	  y=i;
	}
      }
    }
    sum+=min*100;
    p=d[y][0];
    d[y][1]=1;
    cnt++;
    if(cnt==m) break;
  }
  printf("%d\n", sum);
  return 0;
}