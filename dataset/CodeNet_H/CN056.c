int main(void)
{
	int n;
	char prime[50000] = {0};
	int i, j;
	for (i = 2; i < 50000; i++){
		prime[i] = 1;
	}
	for (i = 2; i < sqrt(50000); i++){
		if (prime[i] == 1){
			for (j = i * 2; j < 50000; j += i){
				prime[j] = 0;
			}
		}
	}
	scanf("%d", &n);
	while (n != 0){
		int count = 0;
		for (i = 2; i <= n / 2; i++){
			for (j = 2; j < n; j++){
				if ((prime[i] & prime[j]) == 1 && i + j >= n){
					if (i + j == n){
						count++;
					}
					break;
				}
			}
		}
		printf("%d\n", count);
		scanf("%d", &n);
	}
	return 0;
}