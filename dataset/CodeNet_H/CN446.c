  int main(){
   int a,b,n,m,i,j,k;
   int c,d[100];
   for(i=0;i<100;i++){
       d[i] = 0;
   }
   scanf("%d",&n);
   scanf("%d %d",&a,&b);
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
       if(c/(a+i*b)<d[i]/b){
         c += d[i];
       }else{
           int y = c/(a+i*b);
           printf("%d\n",y);
           break;
       }
   }
   return 0;
  }