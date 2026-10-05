int main(void)
{
	int trad[1000];
	int num, day;
	int i;
	memset(trad, 0, sizeof(trad));
	while (~scanf(" %d,%d", &num, &day)){
		trad[num - 1]++;
	}
	for (i = 0; i < 1000; i++){
		if (trad[i] > 1){
			printf("%d,%d\n", i + 1, trad[i]);
		}
	}
	return (0);
}