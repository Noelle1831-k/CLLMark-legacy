int main(void)
{
	int i, j, n;
	int p, l, r, angle;
	int a, b;
	int root_l[10], root_r[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		r = 0;
		p = a;
		angle = 1;
		while (p != b){
			root_r[r] = p;
			p += angle;
			if (angle == 1 && p == 10){
				angle = -1;
				p = 5;
			}
			if (angle == -1 && p == -1){
				angle = 1;
				p = 1;
			}
			r++;
		}
		l = 0;
		p = a;
		angle = -1;
		while (p != b){
			root_l[l] = p;
			p += angle;
			if (angle == 1 && p == 10){
				angle = -1;
				p = 5;
			}
			if (angle == -1 && p == -1){
				angle = 1;
				p = 1;
			}
			l++;
		}
		if (l < r){
			for (j = 0; j < l; j++){
				printf("%d ", root_l[j]);
			}
		}
		else {
			for (j = 0; j < r; j++){
				printf("%d ", root_r[j]);
			}
		}
		printf("%d\n", b);
	}
	return (0);
}