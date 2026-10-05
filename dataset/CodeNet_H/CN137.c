char *gets(char *);
char buf[50];
int main()
{
	int i, n, s, k;
	gets(buf); n = atoi(buf);
	for (i = 1; i <= n; i++) {
		gets(buf); s = atoi(buf);
		printf("Case %d:\n", i);
		for (k = 0; k < 10; k++) {
			s = (s * s / 100) % 10000;
			printf("%d\n", s);
		}
	}
	return 0;
}