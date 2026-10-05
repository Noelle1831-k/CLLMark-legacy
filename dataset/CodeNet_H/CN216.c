int main(void)
{
int a;
while(scanf("%d",&a),a!=-1){
int d=1150;
if(a>30){
d=d+160*(a-30);
a=30;
}
if(a>20){
d=d+140*(a-20);
a=20;
}
if(a>10){
d=d+125*(a-10);
d=10;
}
if(a<=10){
printf("%d?\n",d-4280);
}
}
return 0;
}