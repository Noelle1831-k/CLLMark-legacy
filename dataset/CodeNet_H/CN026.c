int main(void) {
	int i,j,x,y,size,field[10][10],siro = 0,Max = 0;
    for(i = 0;i < 10;i++){
        for(j = 0;j < 10;j++) field[i][j] = 0;
    }
    while(scanf("%d,%d,%d",&x,&y,&size) != EOF){
        for(i = -2;i <= 2;i++){
            for(j = -2;j <= 2;j++){
                if(x + i >= 0 && x + i < 10 && y + j >= 0 && y + j < 10){
    if(size == 1){
        if(abs(i) + abs(j) <= 1) field[y + j][x + i]++;
    }
    else if(size == 2){
        if(i > -2 && i < 2 && j > -2 && j < 2) field[y + j][x + i]++; 
    }
    else if(size == 3){
        if(abs(i) + abs(j) <= 2) field[y + j][x + i]++;
    }
}
            }
        }
    }
    for(i = 0;i < 10;i++){
        for(j = 0;j < 10;j++){
           if(!field[i][j]) siro++;
           if(Max < field[i][j]) Max = field[i][j];
        }
    }
    printf("%d\n%d\n",siro,Max);
	return 0;
}