int ans;
int rot[4][31] = {
	{ 0,1,2,3,4,5,6,22,23,24,12,11,10,18,14,15,16,17,13,19,20,21,7,8,9,25,26,27,28,29,30 },
	{ 0,28,29,30,4,5,6,7,8,9,10,11,12,13,14,16,15,17,18,21,20,19,22,23,24,25,26,27,1,2,3 },
	{ 0,24,2,3,27,5,6,30,8,9,21,11,12,13,14,15,18,17,16,19,20,10,22,23,1,25,26,4,28,29,7 },
	{ 0,1,2,22,4,5,25,7,8,28,10,11,19,15,14,13,16,17,18,12,20,21,3,23,24,6,26,27,9,29,30 }};
int check(char *a)
{
	int i;
	for (i =  2; i <=  9; i++) if (a[i] != a[ 1]) return 0;
	for (i = 11; i <= 12; i++) if (a[i] != a[10]) return 0;
	for (i = 14; i <= 15; i++) if (a[i] != a[13]) return 0;
	for (i = 17; i <= 18; i++) if (a[i] != a[16]) return 0;
	for (i = 20; i <= 21; i++) if (a[i] != a[19]) return 0;
	for (i = 23; i <= 30; i++) if (a[i] != a[22]) return 0;
	return 1;
}
void dfs(char *a, int k)
{
	int i, j;
	char b[31];
	if (check(a)) { if (k < ans) ans = k; return ; }
	if (k > ans) return;
	for (i = 0; i < 4; i++) {
		for (j = 1; j <= 30; j++) b[j] = a[rot[i][j]];
		dfs(b, k+1);
	}
}
int main()
{
	int n, i, t;
	char a[31];
	scanf("%d", &n);
	while (n-- > 0) {
		for (i = 1; i <= 30; i++) scanf("%d", &t), a[i] = t;
		if (check(a)) puts("0");
		else {
			ans = 8;
			dfs(a, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}