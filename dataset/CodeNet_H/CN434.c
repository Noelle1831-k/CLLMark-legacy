int main(void)
{
	int flog[31];
	int d;
	int i;
	for (i = 0; i < 31; i++){
		flog[i] = 0;
	}
	for (i = 0; i < 28; i++){
		scanf("%d", &d);
		flog[d] = 1;
	}
	for (i = 1; i < 31; i++){
		if (flog[i] == 0){
			printf("%d\n", i);
		}
	}
	return (0);
}