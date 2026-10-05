int main(){
  int m,f,b;
  scanf("%d %d %d", &m, &f, &b);
  if(m >= b){
    printf("%d\n", 0);
  }
  else if(m+f >= b){
    printf("%d\n", b-m);
  }
  else{
    printf("NA\n");
  }
  return(0);
}
