int main()
{
	int a,b,n,s;
	while ( scanf("%d%d%d",&a,&b,&n) != EOF ) {
		s=0;
		a %= b;
		while (n--) {
			a *= 10;
			s += (a/b)%10;
			a %= b;
		}
		printf("%d\n", s);
	}
	return 0;
}