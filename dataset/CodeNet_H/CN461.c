main(){
  int m, n, i, count;
  char s[1000005];
  int t[1000005];
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    getchar();
    scanf("%d", &m);
    getchar();
    for(i=0;i<m;i++){
      scanf("%c", &s[i]);
      if(s[i]=='\n') break;
    }
    t[0]=t[1]=0;
    for(i=2;i<m;i++){
      if(s[i]=='I'){
	if(s[i-1]=='O' && s[i-2]=='I') t[i]=t[i-2]+1;
      }
      else t[i]=0;
    }
    count=0;
    for(i=0;i<m;i++){
      if(t[i]>=n) count++;
    }
    printf("%d\n", count);
  }
  return 0;
}