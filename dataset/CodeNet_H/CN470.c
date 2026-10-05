int main(void){
  int w,h;
  int x,y;
  int s;
  while(1){
    scanf("%d %d",&w,&h);
    if(w==0 && h==0){
      break;
    }
    unsigned long long total=0;
    unsigned long long dp[w][h][4];
    for(s=0;s<4;s++){
      for(x=0;x<w;x++){
	if(s==0){
	  dp[x][0][s]=1;
	}
	else{
	  dp[x][0][s]=0;
	}
      }
    }
    for(s=0;s<4;s++){
      for(y=0;y<h;y++){
	if(s==1){
	  dp[0][y][s]=1;
	}
	else{
	  dp[0][y][s]=0;
	}
      }
    }
    for(y=1;y<h;y++){
      for(x=1;x<w;x++){
	for(s=3;s>=0;s--){
	  if(s==0){dp[x][y][s]=dp[x-1][y][2]+dp[x-1][y][0];}
	  if(s==1){dp[x][y][s]=dp[x][y-1][3]+dp[x][y-1][1];}
	  if(s==2){dp[x][y][s]=dp[x-1][y][1];}
          if(s==3){dp[x][y][s]=dp[x][y-1][0];}
	}
      }
    }
    for(s=0;s<4;s++){
      total+=dp[w-1][h-1][s];
    }
    printf("total:%lu\n",total);
    total=total%100000;
    printf("%lu\n",total);
  }
  return 0;
}
