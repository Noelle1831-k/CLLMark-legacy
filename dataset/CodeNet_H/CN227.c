int main()
{
  int a[1000],n,m,sum,i,j,t;
  while(1){
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)break;
    sum=0;
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
	if(a[j]>a[j+1]){
	  t=a[j];
	  a[j]=a[j+1];
	  a[j+1]=t;
	}
      }
    }
    sum=0;
    if(n>m){
    for(i=n%m;i<n;i++){
      if((i-(n%m))%m==0)continue;
      else sum+=a[i];
    }
    if(n%m==0)i++;
    else if(n%m==1)sum+=a[0];
    else{
    for(i=1;i<n%m;i++){
      sum+=a[i];
    }
    }
    }
    else{
      for(i=0;i<n;i++){
	sum+=a[i];
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}
