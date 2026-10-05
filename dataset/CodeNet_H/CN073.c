int main(){
int x,h;
double k;
while(1){
scanf("%d",&x);
scanf("%d",&h);
if(x==0&&h==0)
break;
k=sqrt(h*h+x*x/4);
printf("%lf\n",2*x*k+x*x);
return 0;
}