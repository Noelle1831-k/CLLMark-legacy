int main(void){
   int n, a[10], sum, i;
   scanf("%d", &n);
   while ( n ) {
      for ( i = 0; i < n; i++ ) {
         scanf("%d", &a[i]);
      }
      sum = 32;
      i = 1;
      while ( sum != 0) {
         if (i % 2 != 0) { sum -= ( sum - 1 ) % 5; printf("%d\n", sum); }
         else {
            if ( a[( i / 2 - 1 ) % n] < sum) sum -= a[( i / 2 - 1 ) % n];
            else sum = 0; printf("%d\n", sum);
         }
         i++;
      }
      scanf("%d", &n);
   }
   return 0;
}