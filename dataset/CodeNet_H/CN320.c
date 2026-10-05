int main(){
  int h[6], w[6], i, j, cnt=0, tmp;
  for(i=0; i<6; i++){
    scanf("%d%d", &h[i], &w[i]);
    if(h[i]>w[i]){
      tmp = h[i];
      h[i] = w[i];
      w[i] = tmp;
    }
  }
  for(i=0; i<5; i++){
    if(h[i]==0 && w[i]==0)continue;
    for(j=i+1; j<6; j++){
      if(h[i]==h[j] && w[i]==w[j]){
	cnt++;
	h[j]=0;
	w[j]=0;
	break;
      }
    }        
  }
  if(cnt==3){
    printf("yes\n");
  }else{
    printf("no\n");
  }
  return 0;
}