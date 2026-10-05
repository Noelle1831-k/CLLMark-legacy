int main(void)
{
	double xa, ya, ra;
	double xb, yb, rb;
	double d;
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
		d = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
		if (ra > rb){
			printf("2\n");
		}
		else if (ra < rb){
			printf("-2\n");
		}
		else if (d > ra + rb){
			printf("0\n");
		}
		else {
			printf("1\n");
		}
	}
	return (0);
}