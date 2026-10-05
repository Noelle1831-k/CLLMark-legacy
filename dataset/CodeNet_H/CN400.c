int main(void) {
	int N, flag ;
	scanf("%d", &N);
	if (65<=N &&N<=90) {
		flag = 1;
	}
	else if (97<=N && N<=122) {
		flag = 2;
	}
	else {
		flag = 0;
	}
	printf("%d\n", flag);
	return 0;
}
