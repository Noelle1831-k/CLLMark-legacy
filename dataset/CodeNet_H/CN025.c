int main(int argc,char* argv[]){
  int a[4],b[4],i,j,hit,blow;
  while(scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&b[0],&b[1],&b[2],&b[3]) != EOF){
    hit = blow = 0;
    for(i = 0;i < 4;i++){
      for(j = 0;j < 4;j++){
	if(b[i] == a[j]){
	  if(i == j){
	    hit++;
	    break;
	  }else{
	    blow++;
	    break;
	  }
	}
      }
    }
    printf("%d %d\n",hit,blow);
  }
  return 0;
}