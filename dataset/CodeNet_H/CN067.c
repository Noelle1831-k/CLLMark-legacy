void showmap(int *);
char readmap(int *);
void labeling(int,int*);
void rewrite(int,int*);
void islandcounter(int*);
int main(void){
		int i = 0;
		int map[196]={};
		char ch = 1 ;
	while(ch){
		ch = readmap(map);
		printf("%d",ch);
		for(i=15;i<196;i++){
			if(map[i]){			
				labeling(i,map);
			}
		}
		islandcounter(map);
	}
	return 0;
}
char readmap (int *map){
	char reader[12]={};			
	char ch = 1;
	int i;
	int j;
	for(i=1;i<=12;i++){
		scanf("%s",reader);
		for(j=1;j<=12;j++){
			map[(i*14)+j] = reader[j-1] - '0';
		}
	}
	scanf("%c",&ch);
			if(ch == EOF){
				return 1;
			}
			return 0;
}
void showmap (int *map){
	int i;
	int j;
	int k = 0 ;
	for(i=1;i<=14;i++){
		for(j=1;j<=14;j++){
			printf("%2d",map[k]);
			k++;
		}
		printf("\n");
	}
}
void labeling(int i,int *map){
	static int label = 1 ;		
	if(!map[i-14] && !map[i-1]){
	label++;		
	map[i]=label;
	}
	else if(map[i-14] && !map[i-1]){	
	map[i]=map[i-14];
	}
	else if(!map[i-14] && map[i-1]){	
	map[i]=map[i-1];
	}
	else if(map[i-14] && map[i-1]){		
		map[i] = map[i-1];
		if(map[i-14] != map[i-1]){	
				rewrite(i,map);				
			}
		}
}
void rewrite(int i,int *map){
	int j = 0;
	int max = 0;
	int min = 0;
	if(map[i-1]<map[i-14]){
		max = map[i-14];
		min = map[i-1];
	}
	else{
		max = map[i-1];
		min = map[i-14];
	}
	for(j = 16 ; j <= i ; j++){
		if(map[j] == max){
			map[j] = min;
		}
	}
}
void islandcounter(int*map){
	int i = 0;
	int sum = 0 ;
	int labelflag[73]={};		
	for(i=16;i<182;i++){
		if(map[i]){				
			labelflag[(map[i])] = 1 ;
		}
	}
	for(i=1;i<73;i++){
		sum += labelflag[i];
	}
	printf("%d\n",sum);
}