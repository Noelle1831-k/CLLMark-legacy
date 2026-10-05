#define mem(x,y)		(x*)malloc(sizeof(x)*(y))
#define PI 3.14159265358979
int int_sort(const void* a,const void* b)
{
	if(*(int*)a > *(int*)b)
	{
		return 1;
	}
	else if(*(int*)a == *(int*)b)
	{
		return 0;
	}
	return -1;
}
int main()
{
	int w,h,n;
	int i,j;
	scanf("%d %d",&w,&h);
	scanf("%d",&n);
	int** list = mem(int*,2);
	int** data = mem(int*,n);
	list[0] = mem(int,n);
	list[1] = mem(int,n);
	for(i = 0;i < n;i++)
	{
		data[i] = mem(int,2);
		scanf("%d %d",&data[i][0],&data[i][1]);
		list[0][i] = data[i][0];
		list[1][i] = data[i][1];
	}
	qsort(list[0],n,sizeof(int),int_sort);
	qsort(list[1],n,sizeof(int),int_sort);
	int a,b,c,d;
	a = list[0][(n-1)/2];
	b = list[1][(n-1)/2];
	c = list[0][n/2];
	d = list[1][n/2];
	long long int time = 0;
	long long int maxtime = 0;
	int maxp = 0;
	for(i = 0;i < n;i++)
	{
		int times[4];
		times[0] = abs(a-data[i][0])+abs(b-data[i][1]);
		times[1] = abs(a-data[i][0])+abs(d-data[i][1]);
		times[2] = abs(c-data[i][0])+abs(b-data[i][1]);
		times[3] = abs(c-data[i][0])+abs(d-data[i][1]);
		time += times[0];
		for(j = 0;j < 4;j++)
		{
			if(times[j] > maxtime)
			{
				maxtime = times[j];
				maxp = j;
			}
			else if(times[j] == maxtime)
			{
				if(maxp > j)
				{
					maxp = j;
				}
			}
		}
	}
	printf("%lld\n",time*2-maxtime);
	switch(maxp)
	{
		case 0:
			printf("%d %d\n",a,b);
			break;
		case 1:
			printf("%d %d\n",a,d);
			break;
		case 2:
			printf("%d %d\n",c,b);
			break;
		case 3:
			printf("%d %d\n",c,d);
			break;
	}
	return 0;
}