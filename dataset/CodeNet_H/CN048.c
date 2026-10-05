int main(void){
   double w;
   while ( scanf("%lf", &w) != EOF ) {
      if ( w <= 48) printf("light fly\n");
      else if ( 48 < w && w <= 51 ) printf("fly\n");
      else if ( 51 < w && w <= 54 ) printf("bantam\n");
      else if ( 54 < w && w <= 57 ) printf("feather\n");
      else if ( 57 < w && w <= 60 ) printf("light\n");
      else if ( 60 < w && w <= 64 ) printf("light welter\n");
      else if ( 64 < w && w <= 69 ) printf("welter\n");
      else if ( 69 < w && w <= 75 ) printf("light middle\n");
      else if ( 75 < w && w <= 81 ) printf("middle\n");
      else if ( 81 < w && w <= 91 ) printf("light heavy\n");
      else printf("heavy\n");
   }
   return 0;
}