int map[6][6]={{0,1,1,0,0,0},
			   {0,0,0,1,0,0},
			   {0,1,0,0,0,0},
			   {0,0,0,0,1,1},
			   {0,0,1,0,0,1},
			   {0,1,1,0,0,0}};
int road[6][2]={{1,2},{-1,3},{1,-1},{4,5},{5,2},{2,1}};
int main(){
	int i,j,ct,l;
	char s[105];
	while(1){
		scanf("%s",s);
		if(strcmp(s,"#")==0)break;
		ct=0;
		l=strlen(s);
		for(i=0;i<l;i++){
			ct=road[ct][s[i]-'0'];
			if(ct==-1)break;
		}
		printf("%s\n",(ct==5)?("Yes"):("No"));
	}
	return 0;
}