int main()
{
 long n, i, j,count=0;
 scanf("%ld", &n);
 for(i=2; i<=n; i++){
   int flag=0;
   for(j=2; j<i; j++){
     if(i%j == 0){
       flag=1;
       break;
     }
   }
  if(flag==0){
    count++;
  }
 }
printf("%ld", count);
printf("\n");
return 0;
}