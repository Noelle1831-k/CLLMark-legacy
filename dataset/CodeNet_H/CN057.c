int main(void)
{
	int n;
	int a;
	while (scanf("%d", &n) != EOF){
		switch (n){
		  case 1, 2:
		  	a = n * 2;
			break;
		  case 3:
		  	a = n * 2 + 1;
			break;
		  default:
		    a = (n - (n / 2) + 1) * (n / 2 + 1);
			break;
		}
		printf("%d\n", a);
	}
	return (0);
}