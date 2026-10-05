typedef struct {
	int m;
	int a;
	int b;
} PEOPLE;
int main(void)
{
	PEOPLE people[128];
	int i, n, f, j;
	int sum;
	while (scanf("%d", &n), n){
		for (i = 0; i < n; i++){
			scanf("%d %d %d", &people[i].m, &people[i].a, &people[i].b);
		}
		f = 0;
		for (i = 0; i < n; i++){
			sum = 0;
			for (j = 0; j < n; j++){
				if (people[j].a >= people[i].a && people[j].a < people[i].b){
					sum += people[j].m;
				}
			}
			if (sum > 150){
				f = 1;
				break;
			}
		}
		if (f){
			printf("NG\n");
		}
		else {
			printf("OK\n");
		}
	}
	return (0);
}