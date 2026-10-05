int main(){
  int i,j,n,h[3][2],m[3][2],s[3][2],ha,ma,sa;
  for(i=0;i<3;i++){
    scanf("%d %d %d %d %d %d",&h[i][0],&m[i][0],&s[i][0],&h[i][1],&m[i][1],&s[i][1]);
  }
  for(i=0;i<3;i++){
    ha=h[i][1]-h[i][0];
    ma=60-m[i][0]+m[i][1];
    sa=60-s[i][0]+s[i][1];
    if(s[i][0]>s[i][1])ma-=1;
    if(m[i][0]>m[i][1])ha-=1;
    if(ma==60)ma=0;
    if(sa==60)sa=0;
    printf("%d %d %d\n",ha,ma,sa);
  }
  return 0;
}