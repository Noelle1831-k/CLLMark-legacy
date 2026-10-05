char map[255][255];
int count,n;
void tate();
void yoko();
void naname1();
void naname2();
main(){
  int i, j;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    getchar();
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf("%c", &map[i][j]);
      }
      getchar();
    }
    count=0;
    tate();
    yoko();
    naname1();
    naname2();
    printf("%d\n", count);
  }
  return 0;
}
void tate(){
  int i, j, sum;
  for(j=0;j<n;j++){
    sum=0;
    for(i=0;i<n;i++){
      if(map[i][j]=='0') sum=0;
      if(map[i][j]=='1'){
	sum++;
      }
      if(count<sum) count=sum;
    }
  }
}
void yoko(){
  int i, j, sum;
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<n;j++){
      if(map[i][j]=='0') sum=0;
      if(map[i][j]=='1'){
      sum++;
      }
      if(count<sum) count=sum;
    }
  }
}
void naname1(){
  int i, j, sum;
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<=i;j++){
      if(map[j][i-j]=='0') sum=0;
      if(map[j][i-j]=='1'){
	sum++;
      }
      if(count<sum) count=sum;
    }
  }
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<=i;j++){
      if(map[n-j-1][n-i+j-1]=='0') sum=0;
      if(map[n-j-1][n-i+j-1]=='1'){
	sum++;
      }
      if(count<sum) count=sum;
    }
  }
}
void naname2(){
  int i, j, sum;
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<=i;j++){
      if(map[j][n-i-1+j]=='0') sum=0;
      if(map[j][n-i-1+j]=='1'){
	sum++;
      }
      if(count<sum) count=sum;
    }
  }
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<=i;j++){
      if(map[n-i-1+j][j]=='0') sum=0;
      if(map[n-i-1+j][j]=='1'){
	sum++;
      }
      if(count<sum) count=sum;
    }
  }
}