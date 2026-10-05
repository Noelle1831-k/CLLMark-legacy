int a[3]={1,0,0};
int ctoi(char c){
  return ((int)c)-65;
}
char itoc(int n){
  return (char)(n+65);
}
void judge(){
  char s[4];
  if(scanf("%s",s)!=EOF){
    int p=ctoi(s[0]);
    int q=ctoi(s[2]);
    int tmp=a[p];
    a[p]=a[q];
    a[q]=tmp;
    judge();
  }
  else{
    int f=0;
    int i=0;
    while((f==0)&&(i<3)){
      if(a[i]==1){
	printf("%c\n",itoc(i));
	f=1;
      }
    }
  }
}
int main(){
  judge();
  return 0;
}