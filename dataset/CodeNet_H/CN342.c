#define _CRT_SECURE_NO_WARNINGS
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
#define max(a,b) a>b?a:b
int comp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int main() {
	int n, a[1000], ab, cd,i;
	double ans=0.0;
	fscanf(stdin, "%d", &n);
	for (i = 0; i < n; i++) fscanf(stdin, "%d", &a[i]);
	qsort(a, n, sizeof(int), comp);
	for (i = 1; i < n; i++) {
		cd = a[i] - a[i - 1];
		if (i == n - 1) ab = a[n - 3] + a[n - 4];
		else if (i == n - 2) ab = a[n - 1] + a[n - 4];
		else ab = a[n - 1] + a[n - 2];
		ans = max(ans, (double)ab / cd);
	}
	P(lf, ans);
	return 0;
}