int main(void){
	int sum, book;
	int i;
	while (scanf("%d", &sum), sum){
		for (i = 0; i < 9; i++){
			scanf("%d", &book);
			sum -= book;
		}
		printf("%d\n", sum);
	}
	return 0;
}