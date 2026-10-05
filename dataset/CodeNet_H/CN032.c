int main(void)
{
	int a;
	int b;
	int c;
	int t;
	int h;
	t = 0;
	h = 0;
	while (scanf ("%d,%d,%d", &a, &b, &c) != EOF){
		if (a * a + b * b == c * c){
			t++;
		}
		else if (a == b){
			h++;
		}
	}
	printf ("%d\n", t);
	printf ("%d\n", h);
	return (0);
}