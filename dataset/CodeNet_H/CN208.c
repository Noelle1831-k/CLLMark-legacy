long long memo[20];
long long get_add(long long input);
long long get_add2(long long count,int count2) {
	long long result;
	if(memo[count2]>0)return memo[count2]-1;
	result=get_add(count-1);
	memo[count2]=result+1;
	return result;
}
long long get_add(long long input) {
	long long result=0;
	long long input2;
	long long input3;
	long long count;
	int count2;
	if(input<=0)return 0;
	for(input2=input,count=1,count2=0;
		input2>=10;
		input2/=10,count*=10,count2++);
	input3=input2;
	if(input2>=4){result+=count;input3--;}
	if(input2>=6){result+=count;input3--;}
	result+=get_add(input-input2*count);
	result+=get_add2(count,count2)*input3;
	return result;
}
int main(void) {
	long long input;
	long long n_add,p_add;
	while(1) {
		scanf("%lld",&input);
		if(input==0)break;
		p_add=0;
		while((n_add=get_add(input))>p_add) {
			input+=n_add-p_add;
			p_add=n_add;
		}
		printf("%lld\n",input);
	}
	return 0;
}