int main(){
  int n;
  char s[11];
  int i,j,k,l;
  int X[12]={0,0,0,1,2,3, 0, 0, 0,-1,-2,-3};
  int Y[12]={1,2,3,0,0,0,-1,-2,-3, 0, 0, 0};
  scanf("%d\n",&n);
  for(i=0;i<n;i++){
    int g[13][13]={0};
    int bx[64]={0};
    int by[64]={0};
    l=1;
    for(j=0;j<8;j++){
      fgets(s,10,stdin);
      for(k=0;k<8;k++){
	g[j+3][k+3]=s[k]-'0';
      }
    }
    scanf("%d\n%d\n",&bx[0],&by[0]);
    bx[0]+=2;
    by[0]+=2;
    for(k=0;bx[k]!=0;k++){
      for(j=0;j<12;j++){
	if(g[by[k]+Y[j]][bx[k]+X[j]]==1){
	  g[by[k]+Y[j]][bx[k]+X[j]]=0;
	  bx[l]=bx[k]+X[j];
	  by[l]=by[k]+Y[j];
	  l++;
	}
      }
    }
    printf("Date %d:\n",i+1);
    for(j=3;j<11;j++){
      for(k=3;k<11;k++){
	printf("%d",g[j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}
