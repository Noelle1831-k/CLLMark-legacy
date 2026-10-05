#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
typedef struct {
	int num,
		fish;
}FISHING;
int main() {
	FISHING *d = (FISHING*)calloc(1000000, sizeof(int));
	int i = 1, n, t, q, num, fish, max, j;
	scanf("%d%d", &n, &q);
	scanf("%d%d", &num, &fish);
	(d + num - 1)->num = num;
	(d + num - 1)->fish += fish;
	max = t = num;
	printf("%d %d\n", (d + t - 1)->num, (d + t - 1)->fish);
	while (i < q) {
		scanf("%d%d", &num, &fish);
		(d + num - 1)->num = num;
		(d + num - 1)->fish += fish;
		if (fish > 0) {
			if ((d + t - 1)->fish < (d + num - 1)->fish) t = num;
			else if ((d + t - 1)->fish == (d + num - 1)->fish) t = t < num ? t : num;
		}
		else {
			t = 1;
			for (j = 1; j <= n; j++) {
				if ((d + t - 1)->fish < (d + j - 1)->fish) t = j;
				else if ((d + t - 1)->fish == (d + j - 1)->fish) t = t < j ? t : j;
			}
		}
		i++;
		printf("%d %d\n", (d + t - 1)->num, (d + t - 1)->fish);
	}
	free(d);
	return 0;
}