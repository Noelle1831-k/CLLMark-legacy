void tennis(int score_a,int score_b)
{
	char game=0;
	int a_count=score_a;
	int b_count=score_b;
	if(score_b>=5)
	{
		game='B';
		b_count=4;
	}
	if(score_a>=5)
	{
		if(game)
		{
			game=1;
		}
		else
		{
			game='A';
		}
		a_count=4;
	}
	int bit_count=a_count+b_count;
	char result[bit_count+1];
	int limit=(int)pow(2,bit_count);
	unsigned int result_bin,cp_result_bin;
	int t_count;
	int echo_count;
	for(result_bin=0x00;result_bin<limit;++result_bin)
	{
		t_count=0;
		for(cp_result_bin=result_bin;cp_result_bin!=0;cp_result_bin&=cp_result_bin-1)
		{
			t_count++;
		}
		echo_count=bit_count-1;
		if(t_count==b_count)
		{
			for(cp_result_bin=result_bin;echo_count>=0;cp_result_bin=cp_result_bin>>1)
			{
				if(cp_result_bin & 0x01)
				{
					result[echo_count--]='B';
				}
				else
				{
					result[echo_count--]='A';
				}
			}
			result[bit_count]='\0';
			printf("%s",result);
			int i;
			if(game!=1)
			{
				for(i=0;score_a+score_b>bit_count+i;++i)
				{
					printf("%c",game);
				}
			}
			else
			{
				printf("AB\n");
				printf("%sBA",result);
			}
			printf("\n");
		}
	}
}
int main()
{
	int score_a,score_b;
	scanf("%d %d",&score_a,&score_b);
	tennis(score_a,score_b);
	return 0;
}
