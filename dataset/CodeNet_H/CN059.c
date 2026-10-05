int main(void){
   int xa1, xa2, xb1, xb2, ya1, ya2, yb1, yb2, key;
   scanf("%d %d %d %d %d %d %d %d %d", &xa1, &ya1, &xa2, &ya2, &xb1, &yb1, &xb2, &yb2);
   if ( xa1 > xa2 ) { xa1 = key; xa1 = xa2; xa2 = key; }
   if ( ya1 > ya2 ) { ya1 = key; ya1 = ya2; ya2 = key; }
   if ( xb1 > xb2 ) { xb1 = key; xb1 = xb2; xb2 = key; }
   if ( yb1 > yb2 ) { yb1 = key; yb1 = yb2; yb2 = key; }
   if ( xa1 < xb1 && xb1 < xa2 ) {
      if ( ya1 < yb1 && yb1< ya2) printf("YES");
      else if (ya1 < yb2 && yb2 < ya2 ) printf("YES");
      else printf("NO");
   }
   else if (xa1 < xb2 && xb2 < xa2 ) {
      if ( ya1 < yb1 && yb1 < ya2 ) printf("YES");
      else if ( ya1 < yb2 && yb2 < ya2 ) printf("NO");
      else printf("NO");
   else printf("NO");
   return 0;
}
