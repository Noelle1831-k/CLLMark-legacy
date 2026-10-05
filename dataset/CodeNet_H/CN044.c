int main(){
	long long int d, min, max, minTmp,maxTmp,j,s;
	while (scanf("%lld", &s) != EOF) {
		min = minTmp = s;
		max = maxTmp = 2;
		d = s;
		while (d<=60000) {
			d += 1;
			for (j = 3; j <= (int)sqrt((double)d); j += 2) {
				if (d%j == 0 || d % 2 == 0) break;
				if (j >= (int)sqrt((double)d) - 1)    min = d;
			}
			if (min != minTmp)  break;
		}
		d = s;
		while (d>=2) {
			d -= 1;
			for (j = 3; j <= (int)sqrt((double)d); j += 2) {
				if (d%j == 0 || d % 2 == 0) break;
				if (j >= (int)sqrt((double)d) - 1)    max = d;
			}
			if (max != maxTmp)  break;
		}
		printf("%lld %lld\n", max,min);
	}
	return 0;
}