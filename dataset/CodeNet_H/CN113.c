#define MAX_N 100
int
main(int argc, char **argv)
{
	int p, q;
	int r[MAX_N];
	int i, j;
	while (scanf("%d %d", &p, &q) != EOF)
	{
		p %= q;
		int n = 0;
		while (p != 0)
		{
			p *= 10;
			if (n >= MAX_N)
			{
				fprintf(stderr, "r area overflow. size:%d\n", MAX_N);
				return 0;
			}
			for (j = 0; j < n; ++j)
			{
				if (r[j] == p)
					break;
			}
			if (j < n)
				break;
			printf("%d", p / q);
			r[n] = p;
			n++;
			p %= q;
		}
		putchar('\n');
		if (p != 0)
		{
			for (i = 0; i < j; ++i)
				putchar(' ');
			for (; i < n; ++i)
				putchar('^');
			putchar('\n');
		}
	}
	return 0;
}