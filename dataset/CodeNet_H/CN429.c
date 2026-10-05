int main(void){
  int i,j,k,n;
  char x[4096],y[4096];
  while(1){
    scanf("%d",&n);
    if(!n) break;
    scanf("%s",x);
    while(n--){
      for(i=k=0;x[i]!='\0';i++){
	for(j=1;x[i+1]==x[i];j++,i++);
	k += sprintf(&y[k],"%d%c",j,x[i]);
      }
      strcpy(x,y);
    }
    printf("%s\n",x);
  }
  return 0;
}