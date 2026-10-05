int m[15][15],c[10000][15][15],b[10000][150]={0};
int min,gy,gx;
int qx[1500000],qy[1500000],s[1500000];
int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};
char d[15][15];
int main(){
  int w,h,i,j,k,ny,nx,r,t,rr,co,x,y,ic;
  while(scanf("%d %d",&w,&h),w||h){
    for(i=0;i<15;i++){
      for(j=0;j<15;j++)d[i][j]=c[0][i][j]=m[i][j]=0;
    }
    min=1000;
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
	scanf(" %c",&d[i][j]);
	if(d[i][j]=='S')d[ y=i][ x=j]='#';
	if(d[i][j]=='G')d[gy=i][gx=j]='.';
      }
    }
    for(i=ic=1;i<=h;i++){
      for(j=1;j<=w;j++){
	if(m[i][j]==0&&d[i][j]=='X'){
	  m[qy[co=0]=i][qx[t=0]=j]=ic;
	  for(r=1;r-t;t++){
	    for(k=0;k<4;k++){
	      nx=qx[t]+X[k];
	      ny=qy[t]+Y[k];
	      if(d[ny][nx]-'X'||m[ny][nx])continue;
	      co++;
	      m[qy[r]=ny][qx[r]=nx]=ic;
	      r++;
	    }
	  }
	  b[0][ic++]=++co/2;
	}
      }
    }
    qx[t=0]=x;
    qy[  0]=y;
    s [  0]=0;
    for(r=rr=1;r-t;t++){
      for(i=0;i<4;i++){
	nx=qx[t]+X[i];
	ny=qy[t]+Y[i];
	if(d[ny][nx]=='#'||d[ny][nx]==0)continue;
	if(c[s[t]][ny][nx])continue;
	c[s[r]=s[t]][qy[r]=ny][qx[r]=nx]=c[s[t]][qy[t]][qx[t]]+1;
	if(gy==ny&&gx==nx)goto END;
	if(d[ny][nx]=='X'){
	  if(b[s[t]][m[ny][nx]]==0)continue;
	  b[s[t]][m[ny][nx]]--;
	  for(j=1;j<=h;j++){
	    for(k=1;k<=w;k++)c[rr][j][k]=c[s[t]][j][k];
	  }
	  for(j=1;j<ic;j++)b[rr][j]=b[s[t]][j];
	  b[s[t]][m[ny][nx]]++;
	  s[r]=rr++;
	}
	r++;
      }
    }
  END:
    printf("%d\n",c[s[t]][gy][gx]);
  }
  return 0;
}