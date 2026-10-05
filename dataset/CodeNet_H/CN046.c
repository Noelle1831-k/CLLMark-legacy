int main(){
double a,b=0,c=1000000;
while(scanf("%lf\n",&a)!=EOF){
if(a>b){
b=a;
}
if(a<c){
c=a;
}
}
printf("%lf\n",b-c);
return 0;
}
