int min(int a, int b)
{
	if (a <= b){
		return (a);
	}
	return (b);
}
int Chain(int a[10000], int n)
{
	int i, j;
	int count;
	int color;
	printf("chain ok\n");
	for (i = 0; i < n - 4; i++){
		if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]){
			count = 0;
			color = a[i];
			for (j = i; a[j] == color; j++){
				a[j] = 0;
				count++;
			}
			for (j = 0; j < count; j++){
				a[i + j] = a[i + j + count];
				a[i + j + count] = 0;
			}
			i = 0;
		}
	}
	count = 0;
	while (a[count] != 0){
		count++;
	}
	printf("count = %d\n", count);
	return (count);
}
int main(void)
{
	int n;
	int i;
	int a[10000];
	int ans;
	while (1){
		for (i = 0; i < 10000; i++){
			a[i] = 0;
		}
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		ans = n;
		for (i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for (i = 1; i < n - 3; i++){
			if (a[i] == a[i + 1] && a[i] == a[i + 2]){
				int buf;
				buf = a[i - 1];
				a[i - 1] = a[i];
				ans = min(ans, Chain(a, n));
				a[i - 1] = buf;
				buf = a[i + 3];
				a[i + 3] = a[i];
				ans = min(ans, Chain(a, n));
				a[i + 3] = buf;
			}
		}
		printf("%d\n", ans);
	}
	return (0);
}