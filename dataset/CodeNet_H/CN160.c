int main(void)
{
	int n, i, x, y, h, w, sum;
	while (1){
		sum = 0;
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		for (i = 0; i < n; i++){
			scanf("%d %d %d %d", &x, &y, &h, &w);
			if (x + y + h > 160 || w > 25){
				sum += 0;
			}
			else if (x + y + h > 140 || w > 20){
				sum += 1600;
			}
			else if (x + y + h > 120 || w > 15){
				sum += 1400;
			}
			else if (x + y + h > 100 || w > 10){
				sum += 1200;
			}
			else if (x + y + h > 80 || w > 5){
				sum += 1000;
			}
			else if (x + y + h > 60 || w > 2){
				sum += 800;
			}
			else {
				sum += 600;
			}
		}
		printf("%d\n", sum);
	}
	return (0);
}