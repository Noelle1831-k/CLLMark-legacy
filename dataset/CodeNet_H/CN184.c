int main(void)
{
	int n,i,age;
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		int age_count[7] = {0};
		for (i = 0; i < n; i++) {
			scanf("%d", &age);
			if (age < 10)
				age_count[0]++;
			else if (age >= 10 && age < 20)
				age_count[1]++;
			else if (age >= 20 && age < 30)
				age_count[2]++;
			else if (age >= 30 && age < 40)
				age_count[3]++;
			else if (age >= 40 && age < 50)
				age_count[4]++;
			else if (age >= 50 && age < 60)
				age_count[5]++;
			else
				age_count[6]++;
		}
		for (i = 0; i < 7; i++) {
			printf("%d\n", age_count[i]);
		}
	}
	return 0;
}