int main()
{
	double a[7];
	int i;
	int flag = 1;
	double x, y;
	while (flag) {
		for (i = 0; i < 6;i++) {
			scanf("%lf",&a[i]);
		}
		if (i == 6) {
			if (getchar() != '\n') {
				flag = 0;
			}
			else {
				flag = 1;
			}
		}
		y = (a[5] - a[3] * a[2] / a[0]) / (-a[3] * a[1] / a[0] + a[4]);
		x = (a[2] / a[0]) - a[1] * ((a[5] - a[3] * a[2] / a[0]) / (-a[3] * a[1] / a[0] + a[4])) / a[0];
		printf("%.3f %.3f\n", x, y);
	}
	return 0;
}