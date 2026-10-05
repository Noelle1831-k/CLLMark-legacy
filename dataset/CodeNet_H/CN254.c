int main(){
  int i,cnt=0,n,l[4]={};
  int s[4]={};
  scanf("%d",&n);
  int a=n;
  if(n == 6174){
    printf("0\n");
    return 0;
  }
  for(i=3;i>=0;i--){
    int aa=a%10;
    l[i]=aa;
    a /= 10;
  }
  if(l[0] == l[1] && l[0] == l[2] && l[0] == l[3]){
    printf("NA\n");
    return 0;
  }
  while(n != 6174){
    int len1,len2;
    for(len1=0;len1<3;len1++){
      for(len2=0;len2<3-len1;len2++){
	if(l[len2] < l[len2+1]){
	  int temp = l[len2];
	  l[len2] = l[len2+1];
	  l[len2+1] = temp;
	}
      }
    }   
    int j=0;
    for(i=3;i>=0;i--){
      s[j]=l[i];
      j++;
    }
    int ll=0,ss=0,ba=1000;
    for(i=0;i<4;i++){
      ll += l[i]*ba;
      ss += s[i]*ba;
      ba /= 10;
    }
    n = ll - ss;
    cnt++;
    a=n;
    for(i=3;i>=0;i--){
      int aa=a%10;
      l[i]=aa;
      a /= 10;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
