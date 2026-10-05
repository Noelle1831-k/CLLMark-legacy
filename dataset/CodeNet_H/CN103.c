int main(){
int out,n,k,g[3],i,x;
char t[5],e1[4]="OUT",e2[4]="HIT",e3[8]="HOMERUN";
scanf("%d",&n);
while(n-->0){
out=0;
k=0;
g[0]=0;
g[1]=0;
g[2]=0;
while(out!=3){
scanf("%s",t);
if(strcmp(e1,t)==0)
out++;
else if(strcmp(e2,t)==0){
if(g[2]==1)
k++;
g[2]=g[1];
g[1]=g[0];
g[0]=1;
}
else {
x=0;
for(i=0;i<3;i++)
if(g[i]==1)
x++;
k=k+x+1;
}
}
printf("%d\n",k);
}
return 0;
}