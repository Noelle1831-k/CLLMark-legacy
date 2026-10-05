char tbl[300005];
int main()
{
	int N, Q, i, k, q, max;
	scanf("%d%d", &N, &Q);
	tbl[0] = 1, max = 0; while (N-- > 0) {
		scanf("%d", &k), tbl[k] = 1;
		if (k > max) max = k;
		tbl[k & 1] = 1, tbl[k & 3] = 1, tbl[k & 7] = 1;
	}
	while (Q-- > 0) {
		scanf("%d", &q);
		if (q > max) printf("%d\n", max);
		else {
			for (k = q-1; ; k--) {
				for (i = k; i <= max; i += q)
					if (tbl[i]) { printf("%d\n", k); goto Done; }
			}
			Done:;
		}
	}
	return 0;
}