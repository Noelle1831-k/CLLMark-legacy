  int main(){
	  int i,k,n,m,j;
   double a,q;
   int c,d[100];
   for(i=0;i<100;i++){
	   d[i] = 0;
   }
   scanf("%d",&n);
   scanf("%d %d",&a,&q);
   scanf("%d",&c);
   for(i=0;i<n;i++){
	   scanf("%d",&d[i]);
   }
   for(j=0;j<n;j++){
	   for(k=0;k<n-1;k++){
		   if(d[k]<d[k+1]){
              m = d[k+1];
			  d[k+1] =d[k];
			  d[k] = m;
		   }
	   }
   }
   for(i=0;i<n;i++){
	   if(c/a < d[i]/q){
		 c += d[i];
	   }else{
		   int x = c/(a+i*q);
		   printf("%d",x);
		   break;
	   }
   }
   return 0;
  }