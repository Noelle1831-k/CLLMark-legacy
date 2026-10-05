int main(void)
{
	int n,i,score;
	char s;
	int c[1000];
	while (1) {
		n = 0;
		score = 0;
		do{
			scanf("%d", &c[n++]);
		} while (scanf("%c", &s), s != '\n');
		if (c[0]==0)break;
		for (i = 0; i < n; i++) {
			if (c[i] >= 2 && c[i] <= 9) {
				score += c[i];
				c[i] = 0;
			}
			else if (c[i] >= 10 && c[i] <= 13) {
				score += 10;
				c[i] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			if (c[i] != 0) {
				if (score + 11 <= 21) {
					score += 11;
				}
				else score += 1;
			}
		}
		if (score > 21)printf("0\n");
		else printf("%d\n",score);
	}
	return 0;
}