int main(){
    int a,b,x,c=0;
    scanf("%d%d%d",&a,&b,&x);
    x=(x+499)/500; 
    c+=fmin(a,2*b)*(x/2); 
    c+=fmin(a,b)*(x%2); 
    printf("%d\n",c);
}
