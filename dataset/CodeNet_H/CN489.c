int main(void)
{
int game,n,i,j,team[100];
int a,b,c,d,ban[100];
scanf("%d",&n);
for(i=0;i<n;i++){
team[i]=0;
ban[i]=1;
}
game=n*(n-1)/2;
for(i=0;i<game;i++){
scanf("%d %d %d %d",&a,&b,&c,&d);
if(c>d){
team[a-1]+=3;
}
else if(c==d){
team[a-1]+1; 
team[b-1]+1;
else{
team[b-1]+3;
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(team[i]<team[j]){
ban[i]++;
}
printf("%d\n",ban[i]);
}
return 0;
}