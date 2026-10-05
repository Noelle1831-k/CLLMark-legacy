int main()
{
	int n,s[4]={0};
	char b[3];
	for(;;)
	{
		if(scanf("%d",&n)==EOF)
			break;
		scanf(",%s",&b);
		if(!strcmp("A",b))
			s[0]++;
		else if(!strcmp("B",b))
			s[1]++;
		else if(!strcmp("AB",b))
			s[2]++;
		else
			s[3]++;
	}
	for(n=0;n<4;n++)
		printf("%d\n",s[n]);
	return 0;
}