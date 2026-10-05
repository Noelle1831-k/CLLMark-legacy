int main()
{
	float v;
	while(scanf("%f",&v)!=EOF)
		printf("%.f\n",ceil(v*v/98)/5+1);
	return 0;
}