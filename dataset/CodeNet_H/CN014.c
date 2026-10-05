int area(int d)
{
	int sum=0;
	for(int i=1;i<=(600/d)-1;i++){
		sum=sum+d*i*i*d*d;
	}
	return (sum);
}
int main(void)
{
	int d;
	for(int i=1;i<20;i++){
	    while((scanf("%d",&d))>0){
		    printf("%d\n",area(d));
	    }
    }
	return 0;
}
