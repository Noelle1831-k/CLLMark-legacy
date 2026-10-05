int main(void) {
   int h, w, n, key[1005][1005], x, y, i, j, k, l;
   scanf("%d %d %d", &h, &w, &n);
   while ( 1 ) {
      for ( i = 1; i <= h + 1; i++ ) {
         for ( j = 1; j <= w + 1; j++ ) {
            scanf("%d", &key[i][j]);
         }
      }
      for ( k = 0; k < n; k++ ) {
         x = y = 1;
         while (1) {
            if ( key[y][x] == 0 ) {
               key[y][x] = 1;
               y++;
            }
            else if ( key[y][x] == 1 ) {
               key[y][x] = 0;
               x++;
            }
            if ( x == w + 1 || y == h + 1 ) break;
         }
      }
      printf("%d %d\n", x, y);
      scanf("%d %d %d", &h, &w, &n);
      if ( h == 0 && w == 0 && n == 0 ) break;
   }
   return 0;
}