int main()
{
	while(1)
	{
		int i,s=-1,e,d[7]={10,27,3,17,11,19,9};
		for(i=0;i<72;i++)
		{
			char t; 
			if(scanf("%c",&t)==EOF)
				return 0;
			if(t=='1')
			{
				if(s<0)
					s=i;
				else
					e=i;
			}
		}
		for(i=0;i<7;i++)
		{
			if(e-s==d[i])
			{
				printf("%c\n",'A'+i);
				break;
			}
		}
		if(scanf("\n")==EOF)
				return 0;
	}
	return 0;
}