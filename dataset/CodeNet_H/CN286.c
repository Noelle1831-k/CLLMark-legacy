#define SIZE 500
int N, K;
int parts[26][12];
int ans[12];
char buf[1002], *p;
int spool[SIZE+1][12];
char used[SIZE+1]; int top;
int new() { int i, k;	
	used[k=i=top] = 1;
	while (++i < SIZE) if (!used[i]) { top = i; break; }
	return k;
}
void dis(int k) { used[k] = 0; if (k < top) top = k; }	
int in()
{
	int n = 0;
	while (isdigit(*p)) n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}
int gcd(int a, int b) {	int r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}
int lcm(int a, int b) {	return a/gcd(a, b)*b; }
void link(int *a, int *b)
{
	int i, *t, _t;
	t = spool[_t=new()];
	memcpy(t, a, sizeof(ans));
	for (i = 0; i < N; i++) a[i] = t[b[i]];
	dis(_t);
}
int period(int *a)
{
	int i, x, t, ans;
	ans = 1;
	for (i = 0; i < N; i++) {
		x = a[i], t = 1;
		while (x != i) x = a[x], t++;
		ans = lcm(ans, t);
	}
	return ans;
}
void calc(int *a)
{
	int i, n;
	int *t, _t;
	for (i = 0; i < N; i++) a[i] = i;
	while (*p >= ' ') {
		if (isalpha(*p)) link(a, parts[*p++ - 'A']);
		else {
			n = in();
			t = spool[_t=new()];
			if (isalpha(*p)) memcpy(t, parts[*p++ - 'A'], sizeof(ans));
			else { p++, calc(t); }
			n %= period(t);
			while (n--) link(a, t);
			dis(_t);
		}
		if (*p <= ' ' || *p++ == ')') break;
	}
}
int main()
{
	int E, i, j, k, h, g;
	int *t;
	fgets(p=buf, 10, stdin), N = in(), p++, K = in();
	for (i = 0; i < K; i++) {
		fgets(p=buf, 10, stdin);
		t = parts[*p - 'A'], p+= 2, h = in();
		for (j = 0; j < N; j++) t[j] = j;
		for (k = 1; k < h; k++) {
			fgets(p=buf, 30, stdin);
			for (j = 1; j < N; j++, p+=2) if (*p & 1) {
				g = t[j], t[j] = t[j-1], t[j-1] = g;
			}
		}
	}
	fgets(p=buf, 10, stdin), E = in();
	while (E--) {
		fgets(p=buf, 1002, stdin);
		calc(ans);
		printf("%d", ans[0]+1);
		for (j = 1; j < N; j++) printf(" %d", ans[j]+1);
		putchar('\n');
	}
	return 0;
}
