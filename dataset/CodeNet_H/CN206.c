int main(){
  int i,last,f;
  long int d,m,n,g;
  while(scanf("%ld",&d)!=0){
    f=0;g=0;
    if(d==0)break;
    for(i=1;i<=12;i++){
      scanf("%ld %ld",&m,&n);    
      if(f==0){    
	g+=m-n;	
	if(g>d){last=i;f=1;}
      }
    }
    if(f==1)printf("%d\n",last);
    else printf("NA\n");
  }
}