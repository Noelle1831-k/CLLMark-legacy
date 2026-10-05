int mat[9][9],check1[9][9],check2[9][9],check3[9][9],flag[9];
void reflesh(int *flag);
void c_check();
void d_check();
void mass_check(int x,int y);
int main(void){
  int set;
  int i,j,k;
  scanf("%d",&set);
  do{
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
	scanf("%d",&mat[i][j]);
	check1[i][j]=0;
	check2[i][j]=0;
	check3[i][j]=0;
      }
    }
    reflesh(flag);
    c_check();
    d_check();
    for(i=0;i<9;i+=3){
      for(j=0;j<9;j+=3){
	mass_check(i,j);
      }
    }
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
	if(check1[i][j]!=0||check2[i][j]!=0||check3[i][j]!=0) printf("*%d",mat[i][j]);
	else printf(" %d",mat[i][j]);
      }
      putchar('\n');
    }
    if(set-1!=0) putchar('\n');
  }while(--set);
  return 0;
}
void reflesh(int *array){
  int a;
  for(a=0;a<9;a++){
    array[a]=0;
  }
}
void c_check(){
  int a,b;
  for(a=0;a<9;a++){
    for(b=0;b<9;b++){
      if(flag[mat[a][b]-1]==0){
	flag[mat[a][b]-1]+=b+1;
      }else{
	check1[a][b]++;
	check1[a][flag[mat[a][b]-1]-1]++;
      }
    }
    reflesh(flag);
  }
}
void d_check(){
  int a,b;
  for(a=0;a<9;a++){
    for(b=0;b<9;b++){
      if(flag[mat[b][a]-1]==0){
	flag[mat[b][a]-1]+=b+1;
      }else{
	check2[b][a]++;
	check2[flag[mat[b][a]-1]-1][a]++;
      }
    }
    reflesh(flag);
  }
}
void mass_check(int x,int y){
  int a,b,c,d;
  for(a=x;a<x+3;a++){
    for(b=y;b<y+3;b++){
      if(flag[mat[a][b]-1]==0){
	flag[mat[a][b]-1]+=(a-x)*3+(b-y)+1;
      }else{
	for(c=x;c<x+3;c++){
	  for(d=y;d<y+3;d++){
	    if(mat[c][d]==mat[a][b]){
	      check3[c][d]++;
	    }
	  }
	}
      }
    }
  }
  reflesh(flag);
}