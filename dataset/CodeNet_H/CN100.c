int main(void)
{
	int num;
	int employ_num;
	long long employ[4001];
	long long employ_money, employ_sell;
	int i;
	int flag;
	while (1){
		scanf("%d", &num);
		if (num == 0){
			break;
		}
		flag = 0;
		for (i = 0; i < num; i++){
			scanf("%d%lld%lld", &employ_num, &employ_money, &employ_sell);
			employ[employ_num] += employ_sell * employ_money;
			if (employ[employ_num] >= 1000000){
				printf("%d\n", employ_num);
				flag = 1;
			}
		}
		if (flag != 1){
			printf("NA\n");
		}
	}
	return (0);
}