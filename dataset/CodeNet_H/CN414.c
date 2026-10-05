int main() {
    int i, l, n;
    char s[101];
    long long oocnt = 0, total_oocnt = 0;
    scanf("%d %d %s", &l, &n, s);
    for ( i=0; i<l-1; ++i ) {
	if ( s[i] == 'o' && s[i+1] == 'o' ) ++oocnt;
    }
    for ( i=0; i<n; ++i ) {
	total_oocnt += oocnt;
	oocnt *= 2;
    }
    printf("%lld\n", 3*total_oocnt + l);
    return 0;
}
