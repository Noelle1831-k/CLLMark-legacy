char *gets(char *);
#define MAX  104729  
#define SQRT 323     
char table[MAX + 5];
int sum[MAX];
int main()
{
	int i, j, n;
	char buf[100];
	for (i = 2; i <= SQRT; i++) {
		if (!table[i]) {
			for (j = i + i; j <= MAX; j = j + i) table[j] = 1;
		}
	}
	j = 2, sum[1] = 2;
	for (i = 3; i <= MAX; i += 2) {
		if (!table[i]) sum[j] = sum[j - 1] + i, j++;
	}
	while (1) {
		gets(buf);
		n = atoi(buf);
		if (n == 0) break;
		printf("%d\n", sum[n]);
	}
	return 0;
}