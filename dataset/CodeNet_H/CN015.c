int main(void)
{
	int a, b, c, d, e, f;
	int min, max;
	int an1, an2, an3, z;
	int flag = 0;
	char str[100000];
	char str2[100000];
	char str3[100000];
	char str4[100000];
	char str5[100000];
	scanf("%d", &a);
	for (b = 0; b < a; b++) {
		scanf("%s", str);
		scanf("%s", str2);
		flag = 0;
		c = 0;
		d = strlen(str);
		e = strlen(str2);
		memset(str4, '0', 100000);
		if (d > e) {
			min = e;
			max = d;
			strcpy(str4, str);
		}
		else {
			min = d;
			max = e;
			strcpy(str4, str2);
		}
		if (min >= 81 || max >= 81) {
			flag = 1;
		}		
		d--;
		e--;
		an2 = 0;
		an3 = 0;
		for (f = min - 1; f >= 0; f--) {
			an1 = (str[d] - '0') + (str2[e] - '0') + an2;
			if (an1 >= 10) {
				str3[c] = (an1 % 10) + '0';
				an2 = an1 / 10;
			}
			else {
				str3[c] = an1 + '0';
				an2 = 0;
			}
			d--;
			e--;
			c++;
			max--;
			an3++;
		}
		max -= 1;
		while (1) {
			if (max == -1 && an2 == 0) {
				break;
			}
			if (max > -1) {
				an1 = (str4[max] - '0') + an2;
				max--;
			}
			else {
				an1 = an2;
			}
			if (an1 >= 10) {
				str3[c] = (an1 % 10) + '0';
				an2 = an1 / 10;
			}
			else {
				str3[c] = an1 + '0';
				an2 = 0;
			}
			c++;
		}
		an3--;
		str3[c] = '\0';
		z = 0;
		if (strlen(str3) >= 81) {
			flag = 1;
		}
		if (flag == 1) {
			printf("overflow\n");
		}
		else {
			for (f = strlen(str3) - 1; f >= 0; f--) {
				printf("%c", str3[f]);
			}
			printf("\n");
		}
		str3[0] = '\0';
	}
	return (0);
}