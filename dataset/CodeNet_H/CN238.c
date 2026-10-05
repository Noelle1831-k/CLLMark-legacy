int main(void){
int t,n,s,f,i;
while(scanf("%d",&t)&&t!=0){
for(i=0;i<t;i++){
scanf("%d",&n);
for(j=0;j<n;j++){
scanf("%d%d",&s,&f);
t=t-s+f;
}
if(t>0)
printf("%d\n",t);
else
printf("OK\n");
}
}
return 0;
}