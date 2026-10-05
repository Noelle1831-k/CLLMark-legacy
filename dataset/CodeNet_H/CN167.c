int main(void) {
	int n,step;
	int i,j,temp;
	while (1) {
		scanf("%d",&n);
		if (n ==0)break;
		int a[n];
		step = 0;
		for (i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					step++;
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		printf("%d\n",step);
	}
	return 0;
}