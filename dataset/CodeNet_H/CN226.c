main(){
  char a[5],b[5];
  int i,j,hit,blow;
  while(1){
    scanf("%s %s",a,b);
    if(a[0]=='0' && a[1]=='\0' && b[0]=='0' && b[1]=='\0') break;
    hit=blow=0;
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
	if(a[i]==b[j]){
	  if(i==j) hit++;
	  else blow++;
	}
      }
    }
    printf("%d %d\n",hit,blow);
  }
  return 0;
}