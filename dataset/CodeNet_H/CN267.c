int main(){
  int n,i,j,t,w,aa,bb,ac,m;
  while(1){
    scanf("%d",&n);
    if(!n)break;
    int a[100001]={0};
    int b[100001]={0};
    aa=0;
    bb=0;
    ac=0;
    w=0;  
    for(i=0;i<n;i++){
      scanf("%d",&m);
      a[m]++;
      if(aa<m)aa=m;
    }
    for(i=0;i<n;i++){
      scanf("%d",&m);
      b[m]++;
      if(bb<m)bb=m;
    }
    if(aa>bb){
      if(n==1)printf("NA\n");
      else    printf("1\n");
    }
    else{
      for(i=bb;i>0;i--){
	w-=b[i];
	for(j=0;j<a[i];j++){
	  w++;
	  ac++;
	  if(w*2>ac)break;
	}
	if(w*2>ac)break;
      }
      if(ac==n)printf("NA\n");
      else     printf("%d\n",ac);
    }
  }
  return 0;
}