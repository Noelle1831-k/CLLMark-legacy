int main(void)
{
	int a, b;
	int sa, sb;
	int n;
	while (1){
		scanf("%d", &n);
		if (!n){
				break;
			}
		sa = sb = 0;
		while (n--){
			scanf("%d%d", &a, &b);
			if (a > b){
				sa += (a + b);
			}
			else if (a < b){
				sb += (a + b);
			}
			else {
				sa += a;
				sb += b;
			}
		}
		printf("%d %d\n", sa, sb);
	}
	return (0);
}