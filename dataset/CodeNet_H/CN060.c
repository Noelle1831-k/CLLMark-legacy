int main(){
int i;
int a,b,c,d;
while(scanf("%d%d%d",&a,&b,&c)!=-1){
d=0;
for(i=1;i<11;i++){
if(i!=a&&i!=b&&i!=c)
if(a+b+i<=20)
d++;
}
if(d>3)
puts("YES");
else
puts("NO");
}
return 0;
}