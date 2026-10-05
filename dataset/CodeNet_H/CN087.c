int  main()
{
	char num[100]={'\0'};
	char *tp;
	double stack[220]={0};
	int i,j;
	while(fgets(num,sizeof(num),stdin)!=NULL)
	{
		i=0;
		tp=strtok(num," ");
		stack[i]=atof(tp);
		i++;
		while(tp!=NULL)
		{
			tp=strtok(NULL," ");
			if(tp!=NULL)
			{
				if(tp[0]=='+')
				{
					stack[i-2]+=stack[i-1];
					stack[i-1]=0;
					i--;
				}
				else if(tp[0]=='-' && (tp[1]>'0' || tp[1]<'9'))
				{
					stack[i-2]-=stack[i-1];
					stack[i-1]=0;
					i--;
				}
				else if(tp[0]=='*')
				{
					stack[i-2]*=stack[i-1];
					stack[i-1]=0;
					i--;
				}
				else if(tp[0]=='/')
				{
					if(stack[i-1]!=0)
					{
						stack[i-2]/=stack[i-1];
						stack[i-1]=0;
						i--;
					}
					else 
					{
						stack[i-2]=0;
						i--;
					}
				}
				else 
				{
					stack[i]=atof(tp);
					i++;
				}
			}
		}
		printf("%f\n",stack[0]);
	}
return 0;
}