int main(void){
	int n;
	int i, a, b, c;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a*a + b*b == c*c){
			printf("YES\n");
		}else if(b*b + c*c == a*a){
			printf("YES\n");
		}else if(a*a + c*c == b*b){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}