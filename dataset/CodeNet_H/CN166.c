#define MAX 50
#define EPS 10e-5
int main(void)
{
	int n1,n2;
	int i;
	int angle;
	float s1,s2;
	while(1){
		s1 = s2 = 0.0;
		scanf("%d",&n1);
		if(n1 == 0){ break; }
		for(i=0;i<n1-1;i++){
			scanf("%d",&angle);
			s1 += sinf((float)angle/180.0*3.141592);
		}
		scanf("%d",&n2);
		if(n2 == 0){ break; }
		for(i=0;i<n2-1;i++){
			scanf("%d",&angle);
			s1 += sinf((float)angle/180.0*3.141592);
		}
		if(s1 > s2-EPS && s1 < s2+EPS ){
			printf("0\n");
		}
		else if(s1 > s2){
			printf("1\n");		
		}
		else{
			printf("2\n");		
		}
	}
	return 0;
}