int main(void){
	char roma[101];
	int ara;
	int len;
	int temp;
	int cb, c;
	int i;
	while(scanf("%s", roma) != EOF){
		ara = 0;
		len = strlen(roma);
		if(roma[0] == 'I') cb = 1;
		if(roma[0] == 'V') cb = 5;
		if(roma[0] == 'X') cb = 10;
		if(roma[0] == 'L') cb = 50;
		if(roma[0] == 'C') cb = 100;
		if(roma[0] == 'D') cb = 500;
		if(roma[0] == 'M') cb = 1000;
		temp = cb;		
		for(i=1; i < len; i++){
			if(roma[i] == 'I') c = 1;
			if(roma[i] == 'V') c = 5;
			if(roma[i] == 'X') c = 10;
			if(roma[i] == 'L') c = 50;
			if(roma[i] == 'C') c = 100;
			if(roma[i] == 'D') c = 500;
			if(roma[i] == 'M') c = 1000;
			if(cb < c){
				ara -= cb;
			}else{
				ara += cb;
			}
			cb = c;
		}
		ara += cb;
		printf("%d\n", ara);
	}
	return 0;
}