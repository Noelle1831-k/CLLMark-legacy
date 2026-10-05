int main(void)
{
	int o[24][60],n,m,a,b,c;
	for(n=0;n<24;n++)
	{
		for(m=0;m<60;m++)
		{
			o[n][m]=0;
		}
	}
	for(n=0;n<2;n++)
	{
		scanf("%d",&a);
		for(m=0;m<a;m++)
		{
			scanf("%d %d",&b,&c);
			o[b][c]=1;
		}
	}
	for(n=0;n<24;n++)
	{
		for(m=0;m<60;m++)
		{
			if(o[n][m]==1)
			{
				if(m<10)
				{
					printf("%d:0%d ",n,m);
				}
				else
				{
					printf("%d:%d ",n,m);
				}
			}
		}
	}
	printf("\n");
	return 0;
}