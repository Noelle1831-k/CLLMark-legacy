int main(void)
{
	int a;
	float b,c,d;
	while(scanf("%d,%f,%f",&a,&c,&d)!=EOF){
		b=c/d/d;
		if(b>=25){
			printf("%d\n",a);
		}
	}
	return 0;
}