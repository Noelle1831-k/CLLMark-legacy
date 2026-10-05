int time[1000000];
int main(void)
{
	int n, r, l;
	int i;
	int before_time = 0;
	int longest = 0;
	scanf("%d %d %d", &n, &r, &l);
	for (i = 0; i < r; i++){
		int d, t, x;
		scanf("%d %d %d", &d, &t, &x);
		time[d - 1] += t - before_time;
		before_time = t;
	}
	time[d - 1] += 600 - before_time;
	for (i = 1; i < n; i++){
		if (time[longest] < time[i]){
			longest = i;
		}
	}
	printf("%d\n", longest + 1);
	return 0;
}