int n,A[100];
int solve(){
   int i;
   if(A[0]+A[2]!=2*A[1]){
      if(A[1]+A[3]==2*A[2]) return A[0];
      else if(A[0]+A[3]==2*A[2]) return A[1];
      else return A[2];
   }else{
      for(i=2;i<n;i++){
         if(A[i-1]+A[i+1]!=2*A[i]) return A[i+1];
      }
   }
}
int main(void){
   int i;
   while(1){
      scanf("%d",&n);
      if(n==0) break;
      for(i=0;i<n+1;i++){
         scanf("%d",&A[i]);
      }
      printf("%d\n",solve());
   }
   return 0;
}