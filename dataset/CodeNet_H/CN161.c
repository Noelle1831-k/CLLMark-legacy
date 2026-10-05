struct TeamData {
	int id;
	int total_time;
	int rank;
};
int main(void) {
	struct TeamData *p, temp;
	int n, m1, s1, m2, s2, m3, s3, m4, s4;
	int i, j;
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		struct TeamData data[n];
		p = data;
		for (i = 0; i < n; i++) {
			scanf("%d %d %d %d %d %d %d %d %d", &data[i].id, &m1, &s1, &m2, &s2, &m3, &s3, &m4, &s4);
			data[i].total_time = (m1 + m2 + m3 + m4) * 60 + s1 + s2 + s3 + s4;
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if ((p + i)->total_time > (p + j)->total_time) {
					temp = *(p + i);
					*(p + i) = *(p + j);
					*(p + j) = temp;
				}
			}
		}
		for (i = 0; i < n; i++)
			for (i = 0; i < n; i++)
				(p + i)->rank = i + 1;
			for (i = 0; i < n; i++) {
				if ((p + i)->rank == 1 || (p + i)->rank == 2 || (p + i)->rank == n - 1)
					printf("%d\n", (p + i)->id);
			}
	}
	return 0;
}