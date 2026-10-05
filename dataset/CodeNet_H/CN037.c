#define PI 3.14159265358979323
int main(){
	char a[9][6];
	int x,y,m,i;
	while(scanf("%s",a[0])!=EOF){
		for(i=1;i<9;i++)
			scanf("%s",a[i]);
		x=1;
		y=0;
		m=1;
		printf("R");
		while(x!=0||y!=0){
			if(m==0){
				printf("L");
				x--;
				if(y==4||a[2*y+1][x]=='0'){
					if(x==0||a[2*y][x-1]=='0'){
						if(y==0||a[2*y-1][x]=='0')
							m=1;
						else
							m=2;
					}
				}else
					m=3;
			}else if(m==1){
				printf("R");
				x++;
				if(y==0||a[2*y-1][x]=='0'){
					if(x==4||a[2*y][x]=='0'){
						if(y==4||a[2*y+1][x]=='0')
							m=0;
						else
							m=3;
					}
				}else
					m=2;
			}else if(m==2){
				printf("U");
				y--;
				if(x==0||a[2*y][x-1]=='0'){
					if(y==0||a[2*y-1][x]=='0'){
						if(x==4||a[2*y][x]=='0')
							m=3;
						else
							m=1;
					}
				}else
					m=0;
			}else{
				printf("D");
				y++;
				if(x==4||a[2*y][x]=='0'){
					if(y==4||a[2*y+1][x]=='0'){
						if(x==0||a[2*y][x-1]=='0')
							m=2;
						else
							m=0;
					}
				}else
					m=1;
			}
		}
		printf("\n");
	}	
	return 0;
}