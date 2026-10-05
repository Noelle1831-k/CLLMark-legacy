int main(){
  int i=1;
  long long int x ,y ,ans;
    while( scanf( "%lld %lld" ,&x ,&y ) ){
      if( x == 0 && y == 0 ){
	break;
      }
      while( x % y != 0 ){
	ans = x % y;
	x = y;
	y = ans;
	i++;
      }
      if( i == 1 ){
	ans = y;
      }
      printf( "%lld %d\n" ,ans ,i );
      i = 1;
    }
  return 0;
}