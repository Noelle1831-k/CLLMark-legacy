int main()
{
	int many,nam=0;
	int data[6] = {500,100,50,10,5,1};
	int x,a;
	while(scanf("%d",&many) && many != 0)
	{
		nam = 0;
		many = 1000 - many;
		for(x=0; x<6; x++)
		{
			if(many/data[x] > 0)
			{
				nam += ( a = (many/data[x]));
				many -= (a * data[x]);
			}
		}
		printf("%d\n",nam);
	}
	return 0;
}