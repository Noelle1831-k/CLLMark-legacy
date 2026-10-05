int main(void){
	int i,j, H,W,length,x,y;
	char buf[102];
	char field[101][101],check[101][101];
	while(scanf("%d %d",&H,&W)!=EOF){
		if(H==0&&W==0) break;
		fgets(buf,sizeof(buf),stdin);
		for(i=0;i<H;i++){
			for(j=0;j<W;j++) check[i][j]=0;
		}
		for(i=0;i<H;i++){
			fgets(buf,sizeof(buf),stdin);
			length=strlen(buf);
			buf[length-1]='\0';
			for(j=0;j<length;j++) field[i][j]=buf[j];
			field[i][j]='\0';
		}
		x=y=0;
		for(;;){
			check[x][y]+=1;
			if(check[x][y]>1){
				printf("LOOP\n");
				break;
			}
			else{
				if(field[x][y]=='>') y++;
				else if(field[x][y]=='<') y--;
				else if(field[x][y]=='^') x--;
				else if(field[x][y]=='v') x++;
				else if(field[x][y]=='.'){
					printf("%d %d\n",y,x);
					break;
				}
			}
		}
	}
	return 0;
}